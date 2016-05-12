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
#import <CoreLocation/CoreLocation.h>

@class MKPlacemark;

typedef NS_ENUM(int32_t, SHXIPLocationType)
{
    SHXIPLocationTypeFixed = 0,
    SHXIPLocationTypeMobile = 1,
    SHXIPLocationTypeUnknown = 2
};

typedef NS_ENUM(int32_t, SHXAccuracyIndicator)
{
    SHXAccuracyIndicatorUnknown = 0,
    SHXAccuracyIndicatorVenue = 1,
    SHXAccuracyIndicatorBlock = 2,
    SHXAccuracyIndicatorNeighborhood = 3,
    SHXAccuracyIndicatorZip = 4,
    SHXAccuracyIndicatorCity = 5,
    SHXAccuracyIndicatorMSA = 6,
    SHXAccuracyIndicatorDMA = 7,
    SHXAccuracyIndicatorState = 8,
    SHXAccuracyIndicatorRegion = 9,
    SHXAccuracyIndicatorCountry = 10
};

/**
 * Location from IP address
 */
@interface SHXIPLocation : CLLocation <SHXJSONCreatable>

/**
 * Address dictionary
 *
 * This dictionary can be used to initialize `MKPlacemark`. It can also
 * be formatted as an address using `ABCreateStringWithAddressDictionary`,
 * defined in the AddressBookUI framework.
 *
 * The following `addressDictionary` keys will be present in the dictionary if
 * a value for them is known: `kABPersonAddressZIPKey`.
 */
@property (nonatomic, readonly) NSDictionary *addressDictionary;

@property (nonatomic, readonly) SHXIPLocationType locationType;
@property (nonatomic, readonly) SHXAccuracyIndicator accuracyIndicator;

/**
 * Returns an `MKPlacemark` for this IP location and its `addressDictionary`.
 *
 * The following `addressDictionary` keys will be present in the dictionary if
 * a value for them is known: `kABPersonAddressZIPKey`. If a value is not
 * known for any of those fields, then that key will be omitted from the
 * dictionary. All other `addressDictionary` keys will always be omitted.
 *
 * The following placemark properties will contain the same value that is
 * present in the address dictionary with the corresponding key:
 * `postalCode` matches `kABPersonAddressZIPKey`. If the corresponding key
 * is not present in the dictionary, then the matching property will be `nil`.
 * The rest of the `MKPlacemark` properties will always contain `nil`.
 *
 * \return `MKPlacemark` for this IP location
 */
- (MKPlacemark *)createMKPlacemark;

@end
