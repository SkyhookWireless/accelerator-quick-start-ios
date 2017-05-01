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

#import "SHXAccelerator.h"

/**
 * Campaign Venue
 *
 * Note that the `customData` property is optional. It will be nil if no data
 * is set on My.Skyhook for this campaign.
 */
@interface SHXCampaignVenue : NSObject <NSCoding>

@property (readonly, nonatomic) NSNumber *venueIdent;
@property (readonly, nonatomic) NSString *campaignName;
@property (readonly, nonatomic) NSDate *timestamp;
@property (readonly, nonatomic) NSString *customData;
@property (readonly, nonatomic) SHXCampaignVenueEventType eventType;


- (id)initWithVenue:(NSNumber *)venueIdent
           campaign:(NSString *)campaignName
          timestamp:(NSDate *)timestamp
         customData:(NSString *)customData
          eventType:(SHXCampaignVenueEventType)eventType;

- (id)initWithCoder:(NSCoder *)coder;
- (void)encodeWithCoder:(NSCoder *)coder;

/**
 * These compare venueIdent and campaignName only
 */
- (BOOL)isEqualToCampaignVenue:(SHXCampaignVenue *)other;
- (BOOL)isEqual:(id)other;
- (NSUInteger)hash;

- (NSString *)description;

@end
