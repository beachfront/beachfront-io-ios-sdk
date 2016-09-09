//
// Author: Håvard Fossli <hfossli@agens.no>
//
// Copyright (c) 2013 Agens AS (http://agens.no/)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
//#import "AGWindowViewDefines.h"

#if !TARGET_OS_TV
typedef NS_OPTIONS(NSUInteger, BF_AGInterfaceOrientationMask) {
    BF_AGInterfaceOrientationMaskPortrait = (1 << UIInterfaceOrientationPortrait),
    BF_AGInterfaceOrientationMaskLandscapeLeft = (1 << UIInterfaceOrientationLandscapeLeft),
    BF_AGInterfaceOrientationMaskLandscapeRight = (1 << UIInterfaceOrientationLandscapeRight),
    BF_AGInterfaceOrientationMaskPortraitUpsideDown = (1 << UIInterfaceOrientationPortraitUpsideDown),
    BF_AGInterfaceOrientationMaskLandscape = (BF_AGInterfaceOrientationMaskLandscapeLeft | BF_AGInterfaceOrientationMaskLandscapeRight),
    BF_AGInterfaceOrientationMaskAll = (BF_AGInterfaceOrientationMaskPortrait | BF_AGInterfaceOrientationMaskLandscapeLeft | BF_AGInterfaceOrientationMaskLandscapeRight | BF_AGInterfaceOrientationMaskPortraitUpsideDown),
    BF_AGInterfaceOrientationMaskAllButUpsideDown = (BF_AGInterfaceOrientationMaskPortrait | BF_AGInterfaceOrientationMaskLandscapeLeft | BF_AGInterfaceOrientationMaskLandscapeRight),
};
#endif

/**
 * @class BF_AGWindowView
 * @description A view which is added to a UIWindow. It will automatically fill window and rotate along with statusbar rotations.
 */

@interface BF_AGWindowView : UIView

#if !TARGET_OS_TV
@property (nonatomic, assign) BF_AGInterfaceOrientationMask supportedInterfaceOrientations;
#endif
/**
 * @property UIViewController *controller. Convinience for having a strong reference to your controller.
 */
@property (nonatomic, strong) UIViewController *controller;
@property (nonatomic, copy) void (^onDidMoveToWindow)(void);
@property (nonatomic, copy) void (^onDidMoveOutOfWindow)(void);
@property (nonatomic, assign) BOOL onlySubviewsCapturesTouch;

- (id)initAndAddToWindow:(UIWindow *)window;
- (id)initAndAddToKeyWindow;

- (void)addSubViewAndKeepSamePosition:(UIView *)view;
- (void)addSubviewAndFillBounds:(UIView *)view;
- (void)addSubviewAndFillBounds:(UIView *)view withSlideUpAnimationOnDone:(void(^)(void))onDone;
- (void)fadeOutAndRemoveFromSuperview:(void(^)(void))onDone;
- (void)slideDownSubviewsAndRemoveFromSuperview:(void(^)(void))onDone;

- (void)bringToFront;
- (BOOL)isInFront;

+ (NSArray *)allActiveWindowViews;
+ (BF_AGWindowView *)firstActiveWindowViewPassingTest:(BOOL (^)(BF_AGWindowView *windowView, BOOL *stop))test;
+ (BF_AGWindowView *)activeWindowViewForController:(UIViewController *)controller;
+ (BF_AGWindowView *)activeWindowViewContainingView:(UIView *)view;

@end

@interface BF_AGWindowViewHelper : NSObject

#if !TARGET_OS_TV
BOOL UIInterfaceOrientationsIsForSameAxis(UIInterfaceOrientation o1, UIInterfaceOrientation o2);
CGFloat UIInterfaceOrientationAngleBetween(UIInterfaceOrientation o1, UIInterfaceOrientation o2);
CGFloat UIInterfaceOrientationAngleOfOrientation(UIInterfaceOrientation orientation);
BF_AGInterfaceOrientationMask BF_AGInterfaceOrientationMaskFromOrientation(UIInterfaceOrientation orientation);
#endif

@end