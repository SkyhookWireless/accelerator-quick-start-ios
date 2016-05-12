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

#import "SHXJSONCreatable.h"

@class MKPlacemark;
@class SHXAdCategory;
@class SHXContactInfo;

/**
 * Venue Information
 */
@interface SHXVenueInfo : NSObject <SHXJSONCreatable>

/**
 * The venue identifier.
 */
@property (nonatomic, readonly) NSNumber *venueIdent;

/**
 * The placemark stores the center coordinate of the venue in its `location`
 * property, the venue set name in its `name` property, and the street address
 * fields that are present in its `addressDictionary` property.
 *
 * The center point will be stored in the `coordinate` property of the
 * `location` `CLLocation` property. None of the other fields of `CLLocation`
 * will be populated.
 *
 * The following `addressDictionary` keys will be present in the dictionary if
 * a value for them is known: `kABPersonAddressStreetKey`,
 * `kABPersonAddressCityKey`, `kABPersonAddressStateKey`,
 * `kABPersonAddressCountryCodeKey`, and `kABPersonAddressZIPKey`. If a value
 * is not known for any field, then that key will be omitted from the
 * dictionary. All other `addressDictionary` keys will always be omitted.
 *
 * The following placemark properties will contain the same value that is
 * present in the address dictionary with the corresponding key:
 * `thoroughfare` matches `kABPersonAddressStreetKey`, `locality` matches
 * `kABPersonAddressCityKey`, `administrativeArea` matches
 * `kABPersonAddressStateKey`, `ISOcountryCode` matches
 * `kABPersonAddressCountryCodeKey`, and `postalCode` matches
 * `kABPersonAddressZIPKey`. If the corresponding key is not present in the
 * dictionary, then the matching property will be `nil`. The rest of the
 * `MKPlacemark` properties will always contain `nil`.
 *
 * Note that the `thoroughfare` property is populated with the full street
 * address from `kABPersonAddressStreetKey` which consists of both the house
 * number and the street name, even though it normally should only contain the
 * street name. Also the subThoroughfare should contain only the house number,
 * but it will always be set to `nil`.
 */
@property (nonatomic, readonly) MKPlacemark *placemark;

/**
 * The advertising category.
 */
@property (nonatomic, readonly) SHXAdCategory *adCategory;

/**
 * Contact information.
 */
@property (nonatomic, readonly) SHXContactInfo *contactInfo;

- (id)initWithVenueIdent:(NSNumber *)venueIdent;

/**
 * These compare venueIdent only.
 */
- (BOOL)isEqualToVenueInfo:(SHXVenueInfo *)other;
- (BOOL)isEqual:(id)other;
- (NSUInteger)hash;

- (NSString *)description;

@end
