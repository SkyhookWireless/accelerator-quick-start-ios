//
//  ViewController.m
//  Quick Start
//
//  Created by Alex Pavlov on 6/18/15.
//  Copyright (c) 2015 Skyhook Wireless. All rights reserved.
//

#import "MapViewController.h"

// Make sure you visited https://my.skyhookwireless.com/ to setup campaigns for your app and generate
// the api key. Assign that key to apiKey variable (see below)

static NSString *apiKey = @"";

@interface MapViewController ()

@property (weak, nonatomic) IBOutlet MKMapView *mapView;
@property (nonatomic, strong) CLLocationManager *locationManager;
@property (strong, nonatomic) SHXAccelerator *accelerator;

@end

@implementation MapViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.mapView.delegate = self;
    self.locationManager = [CLLocationManager new];
    self.locationManager.delegate = self;
    
    if (apiKey.length > 0)
    {
        self.accelerator = [[SHXAccelerator alloc] initWithKey:apiKey];
        self.accelerator.delegate = self;
        self.accelerator.optedIn = YES;
        self.accelerator.userID = @"unique-user-id.make-sure-it-is-unique-and-consistent-between-app-restarts";
        [self.accelerator startMonitoringForAllCampaigns];
    }
}

-(void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    if (apiKey.length == 0)
    {
        UIAlertController* alert = [UIAlertController alertControllerWithTitle:@"No App Key"
                                                                      message:@"Please visit my.skyhookwireless.com to create app key, then edit MapViewController"
                                    @" to initialize the apiKey variable and rebuild the app."
                                                               preferredStyle:UIAlertControllerStyleAlert];
        [self presentViewController:alert animated:YES completion:nil];
    }
    
    self.mapView.showsUserLocation =
        ([CLLocationManager authorizationStatus] == kCLAuthorizationStatusAuthorizedAlways);
}

#pragma mark - CLLocationManagerDelegate

-(void)locationManager:(CLLocationManager *)manager didChangeAuthorizationStatus:(CLAuthorizationStatus)status
{
        self.mapView.showsUserLocation = (status == kCLAuthorizationStatusAuthorizedAlways);
}

#pragma mark - SHXAcceleratorDelegate

-(void)accelerator:(SHXAccelerator *)accelerator didFailWithError:(NSError *)error
{
    NSLog(@"accelerator didFailWithError %@", error);
}

-(void)accelerator:(SHXAccelerator *)accelerator didEnterVenue:(SHXCampaignVenue *)venue
{
    // SHXAcceleratorDelegate methods are always executed on main thread. Depending on
    // how much work your code is going to do you might want to run it off main thread.
    NSLog(@"accelerator venue entry: %@ %@", venue, venue.venueIdent);
    
    [accelerator fetchInfoForVenues:@[venue.venueIdent] completion:^(NSArray *venueInfoList, NSError *error)
     {
         if (venueInfoList)
         {
             SHXVenueInfo *venueInfo = venueInfoList[0];
             UILocalNotification *notification = [UILocalNotification new];
             notification.fireDate = nil;
             notification.alertBody = [NSString stringWithFormat:@"Approaching %@", venueInfo.placemark.name];
             notification.soundName = UILocalNotificationDefaultSoundName;
             [[UIApplication sharedApplication] scheduleLocalNotification:notification];
             
             MKPointAnnotation *annotation = [MKPointAnnotation new];
             annotation.coordinate = venueInfo.placemark.coordinate;
             annotation.title = venueInfo.placemark.name;
             [self.mapView addAnnotation:annotation];
         }
         else
         {
             NSLog(@"Error: %@", error);
         }
     }];
}


#pragma mark - MKMapViewDelegate

-(void)mapView:(MKMapView *)mapView didUpdateUserLocation:(MKUserLocation *)userLocation
{
    mapView.showsUserLocation = NO;
    MKCoordinateRegion coordinateRegion = MKCoordinateRegionMakeWithDistance(userLocation.location.coordinate, 1000, 1000);
    [self.mapView setRegion:coordinateRegion animated:YES];
}

- (MKAnnotationView *)mapView:(MKMapView *)mapView viewForAnnotation:(id <MKAnnotation>)annotation
{
    if ([annotation isKindOfClass:[MKPointAnnotation class]])
    {
        static NSString *kReuseId = @"VenuePin";
        MKPinAnnotationView *pinView = (MKPinAnnotationView *) [self.mapView dequeueReusableAnnotationViewWithIdentifier:kReuseId];
        
        if (pinView == nil)
        {
            pinView = [[MKPinAnnotationView alloc] initWithAnnotation:annotation reuseIdentifier:kReuseId];
            pinView.canShowCallout = YES;
        }
        return pinView;
    }
    return nil;
}


@end
