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
 * this llist of conditions and the following disclaimer in the documentation
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

FOUNDATION_EXPORT NSString * const SHXErrorDomain;

typedef NS_ENUM(NSInteger, SHXError)
{
    /**
     * An unspecified error occurred; no more specific information is
     * available. The device logs may provide additional data.
     */
    SHXErrorUnspecified = 1,

    /**
     * Region monitoring is not available on this device
     */
    SHXErrorRegionMonitoringUnavailable,

    /**
     * Location services are not authorized.
     */
    SHXErrorLocationServicesUnauthorized,

    /**
     * Location prompting is not allowed, but authorization to use location
     * services hasn't been determined yet.
     */
    SHXErrorLocationPromptDisabled,

    /**
     * The app reserved too many regions.
     */
    SHXErrorAppReservedTooManyRegions,

    /**
     * Significant location change monitoring is not available on this device.
     */
    SHXErrorSignificantLocationChangeMonitoringUnavailable,

    /**
     * The key is not authorized.
     */
    SHXErrorUnauthorized,

    /**
     * The location manager reported a failure.
     */
    SHXErrorLocationManagerFail,

    /**
     * The location manager reported a region monitoring failure.
     */
    SHXErrorRegionMonitoringFail,

    /**
     * The server is unavailable.
     */
    SHXErrorServerUnavailable,

   /**
     * Cannot determine location.
     */
    SHXErrorCannotDetermineLocation,

    /**
     * The demographic persona is unavailable.
     */
    SHXErrorPersonaUnavailable,

    /**
     * The operation was aborted.
     */
    SHXErrorOperationAborted
};
