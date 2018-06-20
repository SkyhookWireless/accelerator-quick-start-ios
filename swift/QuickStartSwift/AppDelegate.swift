//
//  AppDelegate.swift
//  QuickStartSwift
//
//  Created by Alex Pavlov on 5/29/18.
//  Copyright © 2018 Skyhook. All rights reserved.
//

import UIKit
import UserNotifications
import SkyhookContext

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    let apiKey = ""
    var accelerator: SHXAccelerator?
    var window: UIWindow?

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        
        // Here we check if apiKey is initialized. This is not to showcase Skyhook API usage patterns. We expect you to keep api key
        // hardcoded into program code or plist file. The purpose of the whole if() branch is to alert you that you did not complete
        // an important configuration step. Feel free to skip to the guard branch right away.
        
        if apiKey.isEmpty {
            
            // Throwing alert view from AppDelegate is a little bit tricky. For starters, we need a ViewController
            // instance to put the alert on, but AppDelegate is not a ViewController. We can fetch a reference to ViewController
            // via 'window' property, but the problem is that at this point of execution the main window is not loaded yet.
            // To ensure the alert code execution after iOS creates the root ViewController we schedule block execution via main queue.

            DispatchQueue.main.async {
                let alert = UIAlertController(title: "No App Key",
                                              message: "Please visit my.skyhookwireless.com to create app key, then edit AppDelegate to initialize apiKey variable and rebuild the app",
                                              preferredStyle: .alert)
                self.window?.rootViewController?.present(alert, animated: true, completion: nil)
            }
        }
        else {
            accelerator = SHXAccelerator(key: apiKey)
            UNUserNotificationCenter.current().requestAuthorization(options: [.alert, .sound]) { (granted, error) in }
        }
        
        return true
    }

}

