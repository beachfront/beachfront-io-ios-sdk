//
//  BFInterstitialView.h
//  BFIOSDK
//
//  Created by samyzee on 5/13/13.
//  Copyright (c) 2013 Beachfront Media, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <BFIOSDK/BFAdResponse.h>

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
 The ad response object that was passed during initialization
 */
@property (strong, readonly) BFAdResponse* adResponse;
@end
