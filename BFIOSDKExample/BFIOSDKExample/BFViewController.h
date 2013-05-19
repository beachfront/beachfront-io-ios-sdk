//
//  BFViewController.h
//  BFIOSDKExample
//
//  Created by Sumeru Chatterjee on 5/13/13.
//  Copyright (c) 2013 Beachfront Media LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BFMViewController : UIViewController
- (IBAction)ShowInterstitial:(id)sender;
@property (weak, nonatomic) IBOutlet UITextField *TextAppID;
@property (weak, nonatomic) IBOutlet UITextField *TextAdUnitID;
@end
