//
//  ViewController.h
//  Quick Start
//
//  Created by Alex Pavlov on 6/18/15.
//  Copyright (c) 2015 Skyhook Wireless. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Accelerator.h"
#import <CoreLocation/CoreLocation.h>
#import <MapKit/MapKit.h>
#import "AppDelegate.h"

@interface MapViewController : UIViewController <CLLocationManagerDelegate, MKMapViewDelegate, SHXAcceleratorDelegate>


@end

