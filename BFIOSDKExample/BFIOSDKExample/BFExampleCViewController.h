//
//  BFExampleCViewController.h
//  BFIOSDKExample
//
//  Created by Viktor on 29.01.16.
//  Copyright © 2016 Beachfront Media, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BFExampleCViewController : UIViewController

@property (weak, nonatomic) IBOutlet UITextField *appIdTextField;
@property (weak, nonatomic) IBOutlet UITextField *adUnitIdTextField;
@property (weak, nonatomic) IBOutlet UITableView *tableView;
@property (weak, nonatomic) IBOutlet UIBarButtonItem *refreshAdBtn;

@end
