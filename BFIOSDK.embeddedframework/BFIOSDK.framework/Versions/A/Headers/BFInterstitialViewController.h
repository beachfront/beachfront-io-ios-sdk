//
//  BFInterstitialViewController.h
//  BFIOSDK
//
//  Created by Todd Kuehnl on 5/7/13.
//  Copyright (c) 2013 Beachfront Media, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <BFIOSDK/BFAdResponse.h>

@interface BFInterstitialViewController : UIViewController
/**
 Initializes and returns a newly allocated  BFInterstitialViewController Object

 This is the designated initializer.

 @param dictionary The json dictionary received from the server
 */
-(id)initWithAdResponse:(BFAdResponse*)adResponse;
/**
 The ad response object that was passed during initialization
 */
@property (strong, readonly) BFAdResponse* adResponse;
@end
