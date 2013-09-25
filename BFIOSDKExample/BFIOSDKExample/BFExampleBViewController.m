//
//  BFExampleBViewController.m
//  BFIOSDKExample
//
//  Created by Eric Turner on 8/17/13.
//  Copyright (c) 2013 Beachfront Media, LLC. All rights reserved.
//

#import "BFExampleBViewController.h"
#import <BFIOSDK/BFIOSDK.h>
#import <MediaPlayer/MediaPlayer.h>

@interface BFExampleBViewController ()
@property (nonatomic,strong) MPMoviePlayerController* player;
@end

@implementation BFExampleBViewController


- (void) interstitialClosed:(NSNotification *)notification{
    NSLog(@"Example App Recieved InterstitialClosed notification");
}

- (void) interstitialOpened:(NSNotification *)notification{
    NSLog(@"Example App Recieved InterstitialOpened notification");
}

- (void) interstitialAdPlaying:(NSNotification *)notification{
    NSLog(@"Example App Recieved InterstitialAdPlaying notification");
}

- (void) interstitialAdCompleted:(NSNotification *)notification{
    NSLog(@"Example App Recieved InterstitialAdComplete notification");
}

- (void) prerollAdStarted:(NSNotification *)notification{
    NSLog(@"Example App Recieved preerollAdStarted notification");
}

- (void) prerollAdCompleted:(NSNotification *)notification{
    NSLog(@"Example App Recieved preerollAdComplete notification");
    [self enablePrerollButton];
    /**
     * Since the preroll has completed
     * here, we tell our player to play
     */
    [_player play];
}

////////////////////////////////////////////////////////////////////////////////////
- (void)viewDidLoad
{
    [super viewDidLoad];
    
    if([self respondsToSelector:@selector(edgesForExtendedLayout)])
        self.edgesForExtendedLayout = UIRectEdgeNone;
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(prerollAdStarted:)
                                                 name:BFAdPrerollStartedNotification
                                               object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(prerollAdCompleted:)
                                                 name:BFAdPrerollCompletedNotification
                                               object:nil];
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [self correctUIForOrientation];
    });
}


////////////////////////////////////////////////////////////////////////////////////
-(void)correctUIForOrientation
{
    
    CGFloat spacing = 65;
    UIInterfaceOrientation interfaceOrientation = [[UIApplication sharedApplication] statusBarOrientation];
    
    // position the player
    _playerArea.center = CGPointMake(self.view.center.x, _playerArea.frame.size.height/2);
    
    // position the text field
    _textAppId.center = CGPointMake(self.view.center.x, _playerArea.frame.size.height + spacing);
    
    // position the label
    _labelAppId.frame = CGRectMake(_textAppId.frame.origin.x,
                                   _textAppId.frame.origin.y - _labelAppId.frame.size.height,
                                   _labelAppId.frame.size.width,
                                   _labelAppId.frame.size.height);
    
    // position the text field
    _textAdUnitId.center = CGPointMake(self.view.center.x, _textAppId.center.y + spacing);
    
    // position the label
    _labelAdUnitId.frame = CGRectMake(_textAdUnitId.frame.origin.x,
                                      _textAdUnitId.frame.origin.y - _labelAdUnitId.frame.size.height,
                                      _labelAdUnitId.frame.size.width,
                                      _labelAdUnitId.frame.size.height);
    
    // position the button
    _button.center = CGPointMake(self.view.center.x, _textAdUnitId.center.y + spacing);
    
    
    // position the player
    _player.view.frame = _playerArea.frame;
    
}

- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation
{
    [UIView animateWithDuration:0.25 animations:^{
        [self correctUIForOrientation];
    }];
}

////////////////////////////////////////////////////////////////////////////////////
- (IBAction)ShowInterstitial:(id)sender {
    
    [BFIOSDK showInterstitialAdWithAppID:_textAppId.text
                                adUnitID:_textAdUnitId.text];
}

- (void)disablePrerollButton
{
    [_button setUserInteractionEnabled:NO];
    _button.alpha = 0.5;
}

- (void)enablePrerollButton
{
    [_button setUserInteractionEnabled:YES];
    _button.alpha = 1.0;
}

////////////////////////////////////////////////////////////////////////////////////
- (IBAction)ShowPreroll:(id)sender {
    
    [self disablePrerollButton];
    
    // Set up your own video player
    [self player];
    
    /**
     * Here we call the preroll ad
     * (1) Pass the rect of your player
     * (2) Pass in your 'App ID' and 'Ad Unit ID'
     */
    CGRect myRect = _player.view.frame;
    [BFIOSDK showPrerollAdInView:self.view
                          inRect:myRect
                           AppID:_textAppId.text
                        adUnitID:_textAdUnitId.text];
}


////////////////////////////////////////////////////////////////////////////////////
-(MPMoviePlayerController*)player{
    if(!_player){
        NSString *pathString   = [[NSBundle mainBundle] pathForResource:@"example" ofType:@"m4v"];
        NSURL *url             = [NSURL fileURLWithPath:pathString];
        _player                = [[MPMoviePlayerController alloc] initWithContentURL:url];
        _player.shouldAutoplay = NO;
        _player.scalingMode    = MPMovieScalingModeAspectFit;
        [_player setControlStyle:MPMovieControlStyleDefault];
        
        if([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone)
            _player.view.frame = CGRectMake(0, 0, 320, 180);
        else
            _player.view.frame = CGRectMake(0, 0, 768, 430);
        
        [self.view addSubview:_player.view];
    }
    return _player;
}

@end