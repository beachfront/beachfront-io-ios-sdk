//
//  BFVideoAdView.h
//  BFIOSDK
//
//  Created by Viktor on 30.04.15.
//  Copyright (c) 2015 Beachfront Media. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BFAdResponse.h"
#import <AVKit/AVKit.h>
#import <AVFoundation/AVFoundation.h>
#import "BFEndCardView.h"


static NSString * const kBFIOSDKBundlePath = @"BFIOSDK.bundle";

static const CGFloat kBorderHeight               = 40;
static const CGFloat kCloseButtonSize            = 32;
static const NSTimeInterval kCloseButtonTimeout  = 5.0f;
static const CGFloat kBeachFrontImageViewWidth   = 120;
static const CGFloat kBeachFrontImageViewHeight  = 19;
static const CGFloat kBeachFrontLogoBGViewHeight = 34;
static const CGFloat kIconSpacing                = 10.0f;

#if !TARGET_OS_TV
static const CGFloat kCountdownLabelOffset       = 4.0f;
#else
static const CGFloat kCountdownLabelOffset       = 55.0f;
#endif


@interface BFVideoAdView : UIView
{
    BOOL _isPreroll;
    
    NSTimer __strong *_timer;
    BOOL _start;
    BOOL _firstQuartile;
    BOOL _midPoint;
    BOOL _thirdQuartile;
    BOOL _complete;
}

@property (nonatomic,strong) UILabel* countDownLabel;
@property (nonatomic,strong) NSMutableArray *iconArray;
@property (nonatomic,strong) UIButton* closeButton;
@property (nonatomic,strong) UIButton* muteButton;
@property (nonatomic,strong) UIImageView* beachFrontImageView;
@property (nonatomic,strong) AVPlayerLayer* player;
@property (nonatomic,strong) UIView* playerContainer;

@property (nonatomic,strong) UIView *logoBGView;
@property (nonatomic,strong) UITapGestureRecognizer *videoTapGestureRecognizer;
@property (nonatomic,strong) BFAdResponse* adResponse;
@property (nonatomic,strong) BFEndCardView *endCardView;

@property (nonatomic) BOOL isReachSDK;

-(void)initWithAd:(BFAdResponse*)adResponse;
-(void)stopTimer;
-(void)showCloseButton;
-(void)makeTrackingCalls:(NSArray*)urls;
-(void)showInteractiveIcons;

-(void)drawRect:(CGRect)rect;
-(void)registerForNotifications;
-(void)startTimer;

UIImage*  BFIOGetImageFromBundle(NSString* imageName);

// empty
-(void)dismiss;
-(void)movieFinished;
-(void)movieStopped;
-(void)movieStartedPlaying;
-(void)applicationBecameActive:(NSNotification*)notification;

@end
