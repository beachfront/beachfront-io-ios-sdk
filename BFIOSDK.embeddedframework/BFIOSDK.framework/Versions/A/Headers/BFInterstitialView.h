//
//  BFInterstitialView.h
//  BFIOSDK
//
//  Created by samyzee on 5/13/13.
//  Copyright (c) 2013 Beachfront Media, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <BFIOSDK/BFAdResponse.h>

@protocol BFInterstitialViewDelegate;

@interface BFInterstitialView : UIView
/**
 Initializes and returns a newly allocated  BFInterstitialViewController Object

 This is the designated initializer.

 @param dictionary The json dictionary received from the server
 */
-(id)initWithAdResponse:(BFAdResponse*)adResponse;
/**
 Call this method to show the ad view.
 */
-(void)show;
/**
 Call this method to dismiss the ad view.
 */
-(void)dismiss;
/**
 Call this method to pause the video.
 */
-(void)pause;
/**
 Call this method to stop the video.
 */
-(void)stop;
/**
 The ad response object that was passed during initialization
 */
@property (nonatomic, strong, readonly)     BFAdResponse* adResponse;
/**
 The delegate for this view
 */
@property (nonatomic, weak,   readwrite)    id<BFInterstitialViewDelegate> delegate;
@end

@protocol BFInterstitialViewDelegate <NSObject>
@optional
/**
 This delegate callback method is called when the video starts playing.
 */
-(void)interstitialViewDidStartPlayingVideo:(BFInterstitialView*)interstitialView;
/**
 This delegate callback method is called when the video ends playing.
 */
-(void)interstitialViewDidEndPlayingVideo:(BFInterstitialView*)interstitialView;
/**
 This delegate callback method is called when the user presses the close button
 */
-(BOOL)interstitialViewShouldDismiss:(BFInterstitialView*)interstitialView;
/**
 This delegate callback method is called when the user presses the close button
 */
-(void)interstitialViewDidDismiss:(BFInterstitialView*)interstitialView;

@end