//
//  SHXCampaign.h
//  Accelerator
//
//  Created by Alex Pavlov on 4/25/16.
//  Copyright © 2016 Skyhook Wireless, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SHXCampaign : NSObject <SHXJSONCreatable>

@property (readonly, strong, nonatomic) NSString *name;
@property (readonly, strong, nonatomic) NSString *payload;

@end
