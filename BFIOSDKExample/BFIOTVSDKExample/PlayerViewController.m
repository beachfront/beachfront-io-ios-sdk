//
//  PlayerViewController.m
//  BeachFrontBuilderTVOS
//
//  Created by Viktor on 06.10.15.
//  Copyright © 2015 Beachfront Media. All rights reserved.
//

#import "PlayerViewController.h"
#import <BFIOSDK/BFIOSDK.h>

@interface PlayerViewController ()

@end

@implementation PlayerViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(prerollAdStarted:) name:BFAdPrerollStartedNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(prerollAdCompleted:) name:BFAdPrerollCompletedNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(prerollAdCompleted:) name:BFAdPrerollFailedNotification object:nil];
}

-(void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void) prerollAdStarted:(NSNotification *)notification{
    NSLog(@"Example App Recieved preerollAdStarted notification");
}

- (void) prerollAdCompleted:(NSNotification *)notification{
    NSLog(@"Example App Recieved preerollAdComplete notification");
    
    /**
     * Since the preroll has completed
     * here, we tell our player to play
     */
    
    [self.player play];
}

-(void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    
    CGRect myRect = self.view.frame;
    [BFIOSDK showPrerollAdInView:self.view inRect:myRect AppID:_appID];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (UIView *)preferredFocusedView
{
    return nil;
}


/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
