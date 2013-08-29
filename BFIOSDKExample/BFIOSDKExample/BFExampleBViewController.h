//
//  BFExampleBViewController.h
//  BFIOSDKExample
//
//  Created by Eric Turner on 8/17/13.
//  Copyright (c) 2013 Beachfront Media, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BFExampleBViewController : UIViewController
- (IBAction)ShowInterstitial:(id)sender;
@property (weak, nonatomic) IBOutlet UITextField *textAppId;
@property (weak, nonatomic) IBOutlet UITextField *textAdUnitId;
@property (weak, nonatomic) IBOutlet UILabel     *labelAppId;
@property (weak, nonatomic) IBOutlet UILabel     *labelAdUnitId;
@property (weak, nonatomic) IBOutlet UIView      *playerArea;
@property (weak, nonatomic) IBOutlet UIButton    *button;
@end