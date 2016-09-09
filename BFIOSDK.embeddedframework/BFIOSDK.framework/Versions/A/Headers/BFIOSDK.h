//
//  BFIOSDK.h
//  BFIOSDK
//
//  Created by Todd Kuehnl on 5/7/13.
//  Copyright 2013 Beachfront Media, LLC. All rights reserved.


#import <Foundation/Foundation.h>

//BFIOSSDK
#import "BFAdResponse.h"
#import "BFInterstitialView.h"
//#import <BFIOSDK/BFInterstitialViewController.h>
#import "BFPrerollView.h"
#import "BFHTTPRequestOperation.h"
#import <AdSupport/ASIdentifierManager.h>
#import "BF_Reachability.h"

#if !TARGET_OS_TV
#import <CoreTelephony/CTTelephonyNetworkInfo.h>
#import <CoreTelephony/CTCarrier.h>
#endif

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
                          userGender:(NSString*)gender
                             userAge:(NSInteger)age;
+ (void) showInterstitialAdWithAppID:(NSString *)appID
                            adUnitID:(NSString *)adUnitID
                    additionalParams:(NSDictionary*)addParams;

#pragma mark -

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
                  userGender:(NSString*)gender
                     userAge:(NSInteger)age;
+ (void) showPrerollAdInView:(UIView*)view
                      inRect:(CGRect)rect
                       AppID:(NSString *)appID
                    adUnitID:(NSString *)adUnitID
            additionalParams:(NSDictionary*)addParams;

#pragma mark -
+ (void) getInFeedAdInView:(UIView*)view
                    inRect:(CGRect)rect
                     AppID:(NSString *)appID
                  adUnitID:(NSString *)adUnitID
                userGender:(NSString*)gender
                   userAge:(NSInteger)age
                   success:(void (^)(BFPrerollView* inFeedAd))success
                   failure:(void (^)(NSError *error))failure;

+ (void) refreshInFeedAd:(BFPrerollView*) preroll
                   AppID:(NSString *)appID
                adUnitID:(NSString *)adUnitID
              userGender:(NSString*)gender
                 userAge:(NSInteger)age
                 success:(void (^)(BFPrerollView* inFeedAd))success
                 failure:(void (^)(NSError *error))failure;

#pragma mark -

/**
 (Deprecated)
 Shows an advertisement in a modal view
 @param appID The App ID
 @param success The Ad Unit ID
 */
+ (void) showAdWithAppID:(NSString *)appID
                adUnitID:(NSString *)adUnitID;




@end
