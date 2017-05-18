//
//  BFExampleCViewController.m
//  BFIOSDKExample
//
//  Created by Viktor on 29.01.16.
//  Copyright © 2016 Beachfront Media, LLC. All rights reserved.
//

#import "BFExampleCViewController.h"
#import <BFIOSDK/BFIOSDK.h>

//#import "DABFLabeledCircularProgressView.h"

#define INDFEED_ROW 1

@interface BFExampleCViewController ()
@property (nonatomic,strong) BFPrerollView* ad;
@property NSMutableArray* hideCellIndexPaths;
@end

@implementation BFExampleCViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    _hideCellIndexPaths = [[NSMutableArray alloc] init];
    
    __weak BFExampleCViewController* weakSelf = self;
    
    [BFIOSDK getInFeedAdInView:self.tableView inRect:CGRectMake(0, 180, _tableView.frame.size.width, 180) AppID:_appIdTextField.text userGender:nil userAge:0 success:^(BFPrerollView *preroll) {
        
        weakSelf.ad = preroll;
        [weakSelf.tableView addSubview:weakSelf.ad];
        [weakSelf.ad resume];

    } failure:^(NSError *error) {
        weakSelf.ad = nil;
    }];
    
    [[NSNotificationCenter defaultCenter] removeObserver:self name:BFAdPrerollCompletedNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(prerollAdCompleted:)
                                                 name:BFAdPrerollCompletedNotification
                                               object:nil];
}

- (void)viewDidDisappear:(BOOL)animated{
    [super viewDidDisappear:animated];
    
    [[NSNotificationCenter defaultCenter] removeObserver:self name:BFAdPrerollCompletedNotification object:nil];
}
- (IBAction)refreshAdAction:(UIButton *)sender
{
    [BFIOSDK refreshInFeedAd:_ad AppID:_appIdTextField.text userGender:nil userAge:0 success:^(BFPrerollView *preroll) {
        
        [_ad setFrame:CGRectMake(0, 180, _tableView.frame.size.width, 180)];
        [_hideCellIndexPaths removeAllObjects];
        [_tableView beginUpdates];
        [_tableView endUpdates];
        [_ad resume];
        
    } failure:^(NSError *error) {
        
    }];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (indexPath.row == INDFEED_ROW && ![_hideCellIndexPaths containsObject:indexPath])
        [_ad resume];
}

- (void)tableView:(UITableView *)tableView didEndDisplayingCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath*)indexPath
{
    if (indexPath.row == INDFEED_ROW && ![_hideCellIndexPaths containsObject:indexPath])
        [_ad pause];
}

- (int)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 5;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    if (![_hideCellIndexPaths containsObject:indexPath])
        return 180.0f;
    else
        return 0;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"cell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (cell == nil)
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
    
    [cell.textLabel setTextAlignment:(NSTextAlignmentCenter)];
    [cell.textLabel setText:[NSString stringWithFormat:@"%d", indexPath.row]];
    
    return cell;
}

- (void) prerollAdCompleted:(NSNotification *)notification{
    NSLog(@"Example App Recieved preerollAdComplete notification");
    
    BFPrerollView* preroll = notification.userInfo[@"inFeedAd"];
    [_hideCellIndexPaths addObject:[NSIndexPath indexPathForRow:INDFEED_ROW inSection:0]];
    [preroll closeFullscreen];
    
    [preroll setFrame:CGRectZero];
    
    [_tableView reloadData];
}

-(BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    return YES;
}

-(void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation{
    [super didRotateFromInterfaceOrientation:fromInterfaceOrientation];
    
}

- (BOOL)shouldAutorotate
{
    return YES;
}

-(UIInterfaceOrientationMask)supportedInterfaceOrientations
{
    return UIInterfaceOrientationMaskAll;
}

@end
