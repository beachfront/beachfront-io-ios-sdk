//
//  BFIOSDK.h
//  BFIOSDK
//
//  Created by Todd Kuehnl on 5/7/13.
//  Copyright 2013 Beachfront Media, LLC. All rights reserved.


#import <Foundation/Foundation.h>

//BFIOSSDK
#import <BFIOSDK/BFAdResponse.h>
#import <BFIOSDK/BFInterstitialView.h>
#import <BFIOSDK/BFInterstitialViewController.h>
#import <BFIOSDK/BFHTTPRequestOperation.h>

extern NSString * const BFAdInterstitialOpenedNotification;
extern NSString * const BFAdInterstitialStartedNotification;
extern NSString * const BFAdInterstitialCompleteNotification;
extern NSString * const BFAdInterstitialClosedNotification;

@interface BFIOSDK : NSObject
/**
 Shows an advertisement in a modal view
 @param appID The App ID
 @param success The Ad Unit ID
*/
+ (void) showAdWithAppID:(NSString *)appID adUnitID:(NSString *)adUnitID;
@end
