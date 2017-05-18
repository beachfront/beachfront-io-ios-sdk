//
//  BFPrerollView.h
//  BFIOSDK
//
//  Created by Eric Turner
//  Copyright (c) 2013 Beachfront Media, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BFAdResponse.h"
#import "BFVideoAdView.h"

@protocol BFPrerollViewDelegate;

@interface BFPrerollView : BFVideoAdView
/**
 Initializes and returns a newly allocated Object
 
 This is the designated initializer.
 
 @param adResponse The json dictionary received from the server
 @param rect The frame of the video player
 */
-(id)initWithAdResponse:(BFAdResponse*)adResponse
                 inView:(UIView*)view
                 inRect:(CGRect)rect;

/**
 Call this method to show the ad view.
 */
-(void)show;
/**
 Call this method to dismiss the ad view.
 */
-(void)dismiss;

-(void)pause;
-(void)resume;
-(void)setMuted:(BOOL)muted;
-(void)closeFullscreen;

/**
 The ad response object that was passed during initialization
 */
//@property (nonatomic, strong, readonly)     BFAdResponse* adResponse;
/**
 The delegate for this view
 */
@property (nonatomic, weak,   readwrite)    id<BFPrerollViewDelegate> delegate;
@property (nonatomic) BOOL isInFeedAd;
@end

@protocol BFPrerollViewDelegate <NSObject>
@optional
/**
 This delegate callback method is called when the video starts playing.
 */
-(void)prerollViewDidStartPlayingVideo:(BFPrerollView*)prerollView;
/**
 This delegate callback method is called when the video ends playing.
 */
-(void)prerollViewDidEndPlayingVideo:(BFPrerollView*)prerollView;
/**
 This delegate callback method is called when the user presses the close button
 */
-(BOOL)prerollViewShouldDismiss:(BFPrerollView*)prerollView;
/**
 This delegate callback method is called when the user presses the close button
 */
-(void)prerollViewDidDismiss:(BFPrerollView*)prerollView;

@end
