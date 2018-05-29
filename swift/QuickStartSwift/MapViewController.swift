//
//  MapViewController.swift
//  QuickStartSwift
//
//  Created by Alex Pavlov on 5/29/18.
//  Copyright © 2018 Skyhook. All rights reserved.
//

import UIKit
import UserNotifications
import MapKit
import CoreLocation
import SkyhookContext

class MapViewController: UIViewController, MKMapViewDelegate, CLLocationManagerDelegate, SHXAcceleratorDelegate {

    static let kReuseId = "VenuePin"
    
    @IBOutlet weak var mapView: MKMapView!
    let locationManager = CLLocationManager()
    
    var accelerator: SHXAccelerator? {
        get {
            return (UIApplication.shared.delegate as? AppDelegate)?.accelerator
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        mapView.delegate = self
        locationManager.delegate = self
        
        if let accelerator = accelerator {
            accelerator.delegate = self
        }
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        accelerator?.startMonitoringForAllCampaigns()
        
        // Actually, we are not going to show user location on the map. Our goal is to zoom map view
        // to current location. As soon as mapView:didUpdateUserLocation receives first coordinate, we
        // will set showsUserLocation to false
        mapView.showsUserLocation = (CLLocationManager.authorizationStatus() == .authorizedAlways)
    }
    

    // MARK: - CLLocationManagerDelegate
    
    func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        mapView.showsUserLocation = (status == .authorizedAlways)
    }
    
    // MARK: - SHXAcceleratorDelegate
    
    func accelerator(_ accelerator: SHXAccelerator!, didFailWithError error: Error!) {
        
        
        if error._code == SHXError.regionMonitoringUnavailable.rawValue {
            let alert = UIAlertController(title: "Device not supported",
                                          message: "Skyhook SDK requires geofencing, which is not available on your device.",
                                          preferredStyle: .alert)
            present(alert, animated: true, completion: nil)
        }
    }
    
    func accelerator(_ accelerator: SHXAccelerator!, didEnter venue: SHXCampaignVenue!) {
        
        // SHXAcceleratorDelegate methods are always executed on main thread. Depending on
        // how much work your code is going to do you might want to run it off main thread.
        NSLog("accelerator venue entry: \(venue!) \(venue!.venueIdent!)")
        
        accelerator.fetchInfo(forVenues: [venue!.venueIdent!]) { [weak self] (venues, error) in
            
            if let error = error {
                NSLog("Error: \(error)")
                return
            }
            
            // Post notification
            let venueInfo: SHXVenueInfo = venues![0] as! SHXVenueInfo
            let content = UNMutableNotificationContent()
            content.body = "Approaching \(venueInfo.placemark.name ?? "")"
            content.sound = UNNotificationSound.default()
            let request = UNNotificationRequest(identifier: "DemoNotification-\(venue!.venueIdent!)", content: content, trigger: nil)
            UNUserNotificationCenter.current().add(request, withCompletionHandler: nil)
            
            // Add map annotation
            let annotation = MKPointAnnotation()
            annotation.coordinate = venueInfo.placemark.coordinate
            annotation.title = venueInfo.placemark.name
            self?.mapView.addAnnotation(annotation)
        }
    }
    

    // MARK: - MKMapViewDelegate
    
    func mapView(_ mapView: MKMapView, didUpdate userLocation: MKUserLocation) {
        mapView.showsUserLocation = false
        let coordinateRegion = MKCoordinateRegionMakeWithDistance(userLocation.coordinate, 1000, 1000)
        mapView.setRegion(coordinateRegion, animated: true)
    }
    
    func mapView(_ mapView: MKMapView, viewFor annotation: MKAnnotation) -> MKAnnotationView? {
        
        if let pointAnnotation: MKPointAnnotation = annotation as? MKPointAnnotation {
            return mapView.dequeueReusableAnnotationView(withIdentifier: MapViewController.kReuseId) ?? buildPinView(pointAnnotation)
        }
        return nil
    }
    
    func buildPinView(_ annotation: MKPointAnnotation) -> MKPinAnnotationView
    {
        let pinView = MKPinAnnotationView(annotation: annotation, reuseIdentifier: MapViewController.kReuseId)
        pinView.canShowCallout = true
        return pinView
    }
    
}


