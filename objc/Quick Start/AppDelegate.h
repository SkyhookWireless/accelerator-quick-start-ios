//
//  AppDelegate.h
//  Quick Start
//
//  Created by Alex Pavlov on 6/18/15.
//  Copyright (c) 2015 Skyhook Wireless. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <SkyhookContext/Accelerator.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;
@property(strong, nonatomic, readonly) SHXAccelerator* accelerator;

@end

