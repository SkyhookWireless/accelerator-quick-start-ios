//
//  AppDelegate.m
//  Quick Start
//
//  Created by Alex Pavlov on 6/18/15.
//  Copyright (c) 2015 Skyhook Wireless. All rights reserved.
//

#import "AppDelegate.h"

// Make sure you visited https://my.skyhookwireless.com/ to setup campaigns for your app and generate
// the api key. Assign that key to apiKey variable (see below)

static NSString *apiKey = @"";

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
// Uncomment if you want to collect logs into a file
//    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
//    NSString *documentsDirectory = paths[0];
//    NSString *logPath = [documentsDirectory stringByAppendingPathComponent:@"console.log"];
//    freopen([logPath cStringUsingEncoding:NSASCIIStringEncoding],"a+",stderr);

    // Here we check if apiKey is initialized. This is not to showcase Skyhook API usage patterns. We expect you to keep api key
    // hardcoded into program code or plist file. The purpose of the whole if() branch is to alert you that you did not complete
    // and important configuration step. Feel free to skip to the else branch right away.
    
    if (apiKey.length == 0)
    {
        // Throwing alert view from AppDelegate is a little bit tricky, folks. For starters, we need a ViewController
        // instance to put the alert on, but AppDelegate is not a ViewController. We can fetch a reference to ViewController
        // via 'window' property, but the problem is that at this point of execution the main window is not loaded yet.
        // To ensure the alert code execution after iOS creates the root ViewController we have to shcedule the block via main queue.

        [[NSOperationQueue mainQueue] addOperationWithBlock:^
        {
            UIAlertController* alert = [UIAlertController alertControllerWithTitle:@"No App Key"
                                                                           message:@"Please visit my.skyhookwireless.com to create app key, then edit AppDelegate"
                                                                                   @" to initialize the apiKey variable and rebuild the app."
                                                                    preferredStyle:UIAlertControllerStyleAlert];

            // Keep in mind that we assume a single view app here.
            [self.window.rootViewController presentViewController:alert animated:YES completion:nil];
        }];

        // Again, the above instructions might sound a somewhat complicated, but the good news is you do not need to check for
        // app key presence in your app.
    }
    else
    {
        // We use AppDelegate to hold a shared instance of SHXAccelerator. Please note that we do not set a delegate property of accelerator here.
        // The MapViewController is going to subscribe to SHXAccelerator events by assigning self-reference to the delegate property later.
        // Whether this approach fits your app is going to be your call. The major thing to remember is that SHXAccelerator instance lifecycle should match
        // the app lifecycle, rather than a lifecycle of UI element(s).
        
        _accelerator = [[SHXAccelerator alloc] initWithKey:apiKey];
        self.accelerator.optedIn = YES;
        self.accelerator.userID = @"unique-user-id.make-sure-it-is-unique-and-consistent-between-app-restarts";
        
        [application registerUserNotificationSettings:[UIUserNotificationSettings settingsForTypes:UIUserNotificationTypeAlert|UIUserNotificationTypeBadge|UIUserNotificationTypeSound
                                                                                        categories:nil]];
    }

    return YES;
}

@end
