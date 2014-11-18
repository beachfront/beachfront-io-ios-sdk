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
#import <BFIOSDK/BFPrerollView.h>
#import <BFIOSDK/BFHTTPRequestOperation.h>
#import <AdSupport/ASIdentifierManager.h>
#import <CoreTelephony/CTTelephonyNetworkInfo.h>
#import <CoreTelephony/CTCarrier.h>
#import "BF_Reachability.h"

extern NSString * const BFAdInterstitialOpenedNotification;
extern NSString * const BFAdInterstitialStartedNotification;
extern NSString * const BFAdInterstitialCompletedNotification;
extern NSString * const BFAdInterstitialClosedNotification;
extern NSString * const BFAdInterstitialFailedNotification;

extern NSString * const BFAdPrerollStartedNotification;
extern NSString * const BFAdPrerollCompletedNotification;
extern NSString * const BFAdPrerollFailedNotification;


@interface BFIOSDK : NSObject


/**
 Shows an interstitial ad in fullscreen
 @param appID The App ID
 @param success The Ad Unit ID
 */
+ (void) showInterstitialAdWithAppID:(NSString *)appID
                            adUnitID:(NSString *)adUnitID;
+ (void) showInterstitialAdWithAppID:(NSString *)appID
                            adUnitID:(NSString *)adUnitID
                         userGender :(NSString*)gender
                             userAge:(NSInteger)age;



/**
 Shows a preroll ad
 @param rect The display rect of the video player
 @param appID The App ID
 @param success The Ad Unit ID
 */
+ (void) showPrerollAdInView:(UIView*)view
                      inRect:(CGRect)rect
                       AppID:(NSString *)appID
                    adUnitID:(NSString *)adUnitID;
+ (void) showPrerollAdInView:(UIView*)view
                      inRect:(CGRect)rect
                       AppID:(NSString *)appID
                    adUnitID:(NSString *)adUnitID
                 userGender :(NSString*)gender
                     userAge:(NSInteger)age;



/**
 (Deprecated)
 Shows an advertisement in a modal view
 @param appID The App ID
 @param success The Ad Unit ID
 */
+ (void) showAdWithAppID:(NSString *)appID
                adUnitID:(NSString *)adUnitID;



@end
