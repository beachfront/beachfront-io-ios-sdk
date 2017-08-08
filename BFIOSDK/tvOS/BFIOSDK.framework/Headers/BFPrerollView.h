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

@interface BFPrerollView : BFVideoAdView <UIGestureRecognizerDelegate, SCNSceneRendererDelegate>

#if !TARGET_OS_TV
@property (nonatomic,strong) SCNScene *scenes;
@property (nonatomic,strong) SCNNode *videoNode;
@property (nonatomic,strong) SKVideoNode *videoSpriteKitNode;
@property (nonatomic,strong) SCNNode *camerasNode;
@property (nonatomic,strong) SCNNode *cameraRollNode;
@property (nonatomic,strong) SCNNode *cameraPitchNode;
@property (nonatomic,strong) SCNNode *cameraYawNode;
@property (nonatomic,strong) CMMotionManager *motionManager;
@property (nonatomic,strong) UIPanGestureRecognizer *panRecognizer;
@property (nonatomic) float currentAngleX;
@property (nonatomic) float currentAngleY;
@property (nonatomic) float previousX;
@property (nonatomic) float previousY;
@property (nonatomic) BOOL is360;
#endif

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
 Call this method to show the 360 ad view.
 */
-(void)show360;
/**
 Call this method to get the camera angles for the 360 ad view.
 */
-(NSArray *)getCamerasNodeAngles;
/**
 Call this method to finish initializing the 360 ad view.
 */
-(void)finish360;
/**
 Call this method to render the scene for the 360 ad view.
 */
-(void)renderer:(id<SCNSceneRenderer>)renderer updateAtTime:(NSTimeInterval)time;

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
