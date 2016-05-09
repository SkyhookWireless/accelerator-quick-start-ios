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

@class SHXAccelerator;
@class SHXCampaignVenue;

/**
 * The SHXAcceleratorDelegate protocol defines the methods used to receive
 * updates from an SHXAccelerator object.
 */
@protocol SHXAcceleratorDelegate <NSObject>

@optional

/**
 * Tells the delegate that a campaign venue has been entered.
 *
 * Implementation of this method is optional. When using the campaign
 * monitoring feature, you should implement this method, however.
 *
 * \param accelerator The accelerator object that generated the enter event.
 * \param venue The campaign venue entered.
 */
- (void)accelerator:(SHXAccelerator *)accelerator
      didEnterVenue:(SHXCampaignVenue *)venue;

/**
 * Tells the delegate that a campaign venue has been exited.
 *
 * \param accelerator The accelerator object that generated the exit event.
 * \param venue The campaign venue exited.
 */
- (void)accelerator:(SHXAccelerator *)accelerator
       didExitVenue:(SHXCampaignVenue *)venue;

/**
 * Tells the delegate that an error occurred.
 *
 * Implementation of this method is optional. You should implement this
 * method, however.
 *
 * \param accelerator The accelerator object that had the error.
 * \param error The error object containing the reason for the error.
 */
- (void)accelerator:(SHXAccelerator *)accelerator
   didFailWithError:(NSError *)error;

/**
 * Tells the delegate that the operation to start campaign monitoring is
 * complete.
 *
 * This will always be called as a result of calling
 * startMonitoringForCampaign: or startMonitoringForAllCampaigns even if the
 * specified campaign or all campaigns are already being monitored.
 *
 * \param accelerator The accelerator object on which the start campaign
 *                    monitoring operation was requested.
 * \param campaignName The campaign name provided to the original
 *                     startMonitoringForCampaign: call or nil if the original
 *                     operation was startMonitoringForAllCampaigns.
 */
- (void)accelerator:(SHXAccelerator *)accelerator
didStartMonitoringForCampaign:(NSString *)campaignName;

/**
 * Tells the delegate that the operation to stop campaign monitoring is
 * complete.
 *
 * This will always be called as a result of calling
 * stopMonitoringForCampaign: or stopMonitoringForAllCampaigns even if the
 * specified campaign or all campaigns are already being monitored.
 *
 * \param accelerator The accelerator object on which the stop campaign
 *                    monitoring operation was requested.
 * \param campaignName The campaign name provided to the original
 *                     stopMonitoringForCampaign: call or nil if the original
 *                     operation was stopMonitoringForAllCampaigns.
 */
- (void)accelerator:(SHXAccelerator *)accelerator
didStopMonitoringForCampaign:(NSString *)campaignName;

@end
