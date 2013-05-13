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
-(id)initWithAdResponse:(BFAdResponse*)adResponse;
@property (strong, nonatomic) BFAdResponse* adResponse;
@end
