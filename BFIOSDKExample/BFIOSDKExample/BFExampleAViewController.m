//
//  BFMViewController.m
//  BFIOSDKExample
//
//  Created by Todd Kuehnl on 5/7/13.
//  Copyright (c) 2013 Beachfront Media, LLC. All rights reserved.
//

#import "BFExampleAViewController.h"
#import <BFIOSDK/BFIOSDK.h>
#import <MediaPlayer/MediaPlayer.h>

@interface BFExampleAViewController ()
@property (nonatomic,strong) MPMoviePlayerController* player;
@end

@implementation BFExampleAViewController

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


////////////////////////////////////////////////////////////////////////////////////
- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(interstitialOpened:)
                                                 name:BFAdInterstitialOpenedNotification
                                               object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(interstitialClosed:)
                                                 name:BFAdInterstitialClosedNotification
                                               object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(interstitialAdPlaying:)
                                                 name:BFAdInterstitialStartedNotification
                                               object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(interstitialAdCompleted:)
                                                 name:BFAdInterstitialCompletedNotification
                                               object:nil];
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [self correctUIForOrientation];
    });
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
-(void)correctUIForOrientation
{
    
    CGFloat spacing = 65;
    UIInterfaceOrientation interfaceOrientation = [[UIApplication sharedApplication] statusBarOrientation];
    
//    if(UIInterfaceOrientationIsPortrait(interfaceOrientation)){}
    
        // position the text field
        _textAppId.center = CGPointMake(self.view.center.x, spacing);
        
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
        
}

- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation
{
    [UIView animateWithDuration:0.25 animations:^{
        [self correctUIForOrientation];
    }];
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