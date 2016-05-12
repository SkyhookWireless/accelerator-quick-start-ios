/*
 * Copyright (C) 2013-2015 Skyhook Wireless, Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted subject to the following:
 *
 * * Use and redistribution is subject to the Software License and Development
 * Agreement, available at
 * <a href="http://www.skyhookwireless.com">www.skyhookwireless.com</a>
 *
 * * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>

/**
 * Campaign Visit
 */
@interface SHXCampaignVisit : NSObject

/**
 * The name of the campaign
 */
@property (readonly, nonatomic) NSString *campaignName;

/**
 * The time that the venue from this campaign was entered for this visit.
 */
@property (readonly, nonatomic) NSDate *enterTime;

/**
 * The time that the venue from this campaign was exited for this visit. This
 * will be nil if the user is currently at the venue.
 */
@property (readonly, nonatomic) NSDate *exitTime;

/**
 * Custom data set on My.Skyhook for this campaign. This is an optional
 * property which will be nil if no data was specified on the portal.
 */
@property (readonly, nonatomic) NSString *customData;

- (id)initWithCampaignName:(NSString *)campaignName
                 enterTime:(NSDate *)enterTime
                  exitTime:(NSDate *)exitTime
                customData:(NSString *)customData;

- (NSString *)description;

@end
