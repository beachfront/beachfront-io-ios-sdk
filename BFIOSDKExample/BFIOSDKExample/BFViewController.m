//
//  BFViewController.m
//  BFIOSDKExample
//
//  Created by Sumeru Chatterjee on 5/13/13.
//  Copyright (c) 2013 Beachfront Media LLC. All rights reserved.
//

#import "BFViewController.h"
#import <BFIOSDK/BFIOSDK.h>

@interface BFViewController ()

@end

@implementation BFViewController

@synthesize TextAdUnitID, TextAppID;

- (void) interstitialClosed:(NSNotification *)notification{
    NSLog(@"Example App Recieved InterstitialClosed notification");
}

- (void) interstitialOpened:(NSNotification *)notification{
    NSLog(@"Example App Recieved InterstitialOpened notification");
}

- (void) interstitialAdPlaying:(NSNotification *)notification{
    NSLog(@"Example App Recieved InterstitialAdPlaying notification");
}

- (void) interstitialAdComplete:(NSNotification *)notification{
    NSLog(@"Example App Recieved InterstitialAdComplete notification");
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [[NSNotificationCenter defaultCenter]   addObserver:self
                                               selector:@selector(interstitialOpened:)
                                                   name:BFAdInterstitialOpenedNotification
                                                 object:nil];
    
    [[NSNotificationCenter defaultCenter]addObserver:self
                                            selector:@selector(interstitialClosed:)
                                                name:BFAdInterstitialClosedNotification
                                              object:nil];
    
    [[NSNotificationCenter defaultCenter]   addObserver:self
                                               selector:@selector(interstitialAdPlaying:)
                                                   name:BFAdInterstitialStartedNotification
                                                 object:nil];
    
    [[NSNotificationCenter defaultCenter]   addObserver:self
                                               selector:@selector(interstitialAdComplete:)
                                                   name:BFAdInterstitialCompleteNotification
                                                 object:nil];
}

- (IBAction)ShowInterstitial:(id)sender {
    [BFIOSDK showAdWithAppID:TextAppID.text adUnitID:TextAdUnitID.text];
}

@end