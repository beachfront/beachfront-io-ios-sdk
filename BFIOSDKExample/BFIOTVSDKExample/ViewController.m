//
//  ViewController.m
//  BFIOTVSDKExample
//
//  Created by Viktor on 18.05.17.
//  Copyright © 2017 Beachfront Media, LLC. All rights reserved.
//

#import "PlayerViewController.h"
#import "ViewController.h"
#import <AVFoundation/AVFoundation.h>
#import <BFIOTVSDK/BFIOSDK.h>


@interface ViewController ()

@property (nonatomic, strong)   PlayerViewController* playerViewController;

@property (weak, nonatomic) IBOutlet UITextField *appIDTextField;
@property (weak, nonatomic) IBOutlet UIButton *showPrerollBtn;
@property (weak, nonatomic) AVPlayer *avPlayer;
@property (weak, nonatomic) AVPlayerLayer *avPlayerLayer;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.

}

- (UIView *)preferredFocusedView
{
    return _showPrerollBtn;
}


- (IBAction)showPrerollAction:(UIButton *)sender {
    
    self.playerViewController = [PlayerViewController new];
    self.playerViewController.appID = _appIDTextField.text;

    [self.playerViewController.view setFrame:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height)];

    NSURL *videoURL = [NSURL URLWithString:@"https://clips.vorwaerts-gmbh.de/big_buck_bunny.mp4"];
//    NSString *pathString   = [[NSBundle mainBundle] pathForResource:@"example" ofType:@"m4v"];
//    NSURL *videoURL             = [NSURL fileURLWithPath:pathString];
    AVPlayer *player = [AVPlayer playerWithURL:videoURL];
    
    self.playerViewController.player = player;
    [self.view addSubview: self.playerViewController.view];
    [self presentViewController:self.playerViewController animated:YES completion:nil];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
