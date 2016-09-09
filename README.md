
# Guide
Beachfront.io is the easist way monetize your app using Interstitial and Preroll Video Ads. This document shows you how to integrate Beachfront.io into your iOS app.



## What You'll Need
* Xcode version 5.0 or higher
* An iOS app targeting at least iOS version 6.0


## Installing the SDK

1. [Get a Beachfront.io account](http://beachfront.io/join) if you don't already have one.
2. Login to the [dashboard](http://beachfront.io/) and create a new app.
3. Click 'Edit App' and you will see your App ID & Ad Unit Id (copy for later).
3. [Download](https://github.com/beachfront/beachfront-io-ios-sdk) the SDK and drag-drop the BFIOSDK.embeddedframework into your Xcode project folder.
4. In the "Build Phases" section of your project target, navigate to "Copy Bundle Resources" and make sure 'BFIOSDK.bundle' is listed. If not, find it under the Resources folder in BFIOSDK.embeddedframework and drag it in.
5. In the "Build Phases" section of your project target, navigate to "Link Binary with Libraries" and add the BFIOSDK.framework to the list (if not already there).
6. While you're still in "Link Binary with Libraries" add the frameworks:
	* Foundation.framework
	* CoreGraphics.framework
	* MediaPlayer.framework
	* UIKit.framework
	* AdSupport.framework
	* CoreTelephony.framework
	* SystemConfiguration.framework
7. **IMPORTANT**: In the "Build Settings" section of your project target, navigate to "Other Linker Flags" and add '-ObjC' if not already present.
  
8. Import the framework header wherever you want to show an Ad. 

```
 #import <BFIOSDK/BFIOSDK.h>
```




## Showing Interstitial Ads

Whenever you want to show an Interstitial Video Ad use the following method call:    

```
[BFIOSDK showAdWithAppID:@"yourAppID" adUnitID:@"yourAdUnitID"];
```



## Showing Preroll Ads

Whenever you want to show a Preroll Video Ad use the following method call:    

```
    [BFIOSDK showPrerollAdInView:self.view
                          inRect:_yourPlayer.view.frame
                           AppID:@"yourAppID"
                        adUnitID:@"yourAdUnitID"];
```

    
    
## Showing In-Feed Ads

Beachfront.IO In-Feed is a new native ad unit (requires iOS 6.0 and above) that allows you to blend Beachfront.io ads directly into your app’s content, closely matching the form and function of your existing user experience.

In-Feed ads consist user experience is triggered if a user taps on the video container, at which point the Beachfront.IO SDK will open browser with selected Ad.

###Instructions###
Once you've performed the required [[Xcode Project Setup]], you can display an Beachfront.IO In-Feed ads in your app by the following steps:

1. Create or sign into your [Beachfront.IO account](http://platform.beachfront.io/en/login/) and retrieve the Beachfront.IO app ID and Beachfront.IO Ad Unit IDs for your app. For help, see [Beachfront.IO FAQ](http://beachfront.io/faq/).
2. Add code that runs on app launch to configure Beachfront.IO with your app ID and Ad Unit ID.
3. Add code to retrieve an `BFPrerollView` object, and insert it into your native user interface placement.
4. Insert a sponsored content indicator into your placement.
5. Ensure that the native ad will pause and resume properly.

###Code Example - Using the BFPrerollView###
**ViewController.m**
```objc
#import <BFIOSDK/BFIOSDK.h>

@implementation ViewController
/* Class body ... */

- (void)getInFeedAd {
    [BFIOSDK getInFeedAdInView:self.view inRect:CGRectMake(0, 0, 320, 180) AppID:YOUR_APP_ID adUnitID:YOUR_AD_UNIT_ID userGender:nil userAge:0 success:^(BFPrerollView *inFeedAd) {
	[self.view addSubview: inFeedAd]; // insert In-Feed Ad to your view
	[inFeedAd resume]; // play video Ad
        
    } failure:^(NSError *error) {
        // error handling
    }];
```
This example does a lot of things corresponding to the steps outlined in the instructions. We'll go through them one at a time. First, it requests an `BFPrerollView` object using `[BFIOSDK getInFeedAdInView:inRect:AppID:adUnitID:userGender:userAge:success:failure:]`. You must pass a pointer to your UIViewController in which you will display the ad; in this example, that's `self.view`. It's important to note that Beachfront.IO will sometimes return `nil` from this method when ads are not available, so your code _must_ be able to deal with this scenario. We recommend handling it by laying out your user interface as if there was no intention to display an ad. Do not leave a blank space in your user interface where the ad would have been displayed.

Lastly, the example sets a frame size for the native ad in preparation to insert it into the user interface. The `BFPrerollView` is a subclass of `UIView` that includes all the necessary machinery to display the video component of the advertisement and the engagement button, so it's important that it is sized well. Once this is done, your simply insert the `BFPrerollView` into the user interface alongside any other required `UILabel`s or `UIImageView`s that you need to display the rest of the ad content.

###Pausing and Resuming###
In-Feed is designed for use within scrolling content on iOS. The intended user-experience is that the video will begin playing when first displayed, will pause when scrolled off screen, and will resume playing when scrolled back on screen. Unfortunately, because of limitations with the APIs of `UITableView`s and `UIScrollView`s, _your_ code *must* handle cases where the `BFPrerollView` moves off screen and back on again. You also need to handle the case where your view controller containing `BFPrerollView`s disappears and reappears. Finally, you must take care when using re-usable `UITableViewCell`s or `UICollectionViewCell`s.

**Requirements**  
In order to comply with contractual requirements regarding implementation and valid impressions, we require the following from Publishers:   

1. The video player must be in a viewable area and nothing should be covering it.  
2. The video should start/resume playing when 50% of the pixels are within the viewable area.  
3. The video should pause as soon as > 50% of the pixels go out of the viewable area, in any direction.  

**Scrolling Ads On-Screen and Off-Screen**  
Whenever a cell or a view containing an `BFPrerollView` is scrolled off screen, you must call the `pause` method on the corresponding ad view. Likewise, whenever it is scrolled back on screen, you must call the `resume` method. When using a `UITableViewController`, this is as simple as implementing the delegate methods in the following example.

```objc
#import <BFIOSDK/BFIOSDK.h>

@implementation ViewController
/* Class body ... */

- (void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath {
    BFPrerollView* adView = nil; /* TODO: App specific code to get the ad view for the cell ... */
    [adView resume];
}

- (void)tableView:(UITableView *)tableView didEndDisplayingCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath {
    BFPrerollView* adView = nil; /* TODO: App specific code to get the ad view for the cell ... */
    [adView pause];	
}
```

--

**View Controller Visibility**  
We recommend that you store pointers to any `BFPrerollView`s you create in an array in your view controller. Then just iterate over them when you need to pause the ads. When you need to resume ads, you should only resume ones that are currently visible on screen, as shown in the following example, which assumes usage of a `UITableViewController`.

```objc
#import <BFIOSDK/BFIOSDK.h>

@implementation ViewController
/* Class body ... */

- (void)viewWillAppear:(BOOL)animated {
    for(UITableViewCell* cell in [self.tableView visibleCells]) {
    	BFPrerollView* adView = nil; /* TODO: App specific code to get the ad view for the cell ... */
        [adView resume];
    }
}

- (void)viewWillDisappear:(BOOL)animated {
    for(BFPrerollView* adView in adViews) {
        [adView pause];
    }
}
```

--

**In-Feed Ad reuse**  
You can reuse/refresh `BFPrerollView` by using [BFIOSDK refreshInFeedAd:AppID:adUnitID:userGender: userAge:success]. It is resets the In-Feed View, so you do not need to remove the old and create new BFPrerollView. 

```objc
#import <BFIOSDK/BFIOSDK.h>

@implementation ViewController
/* Class body ... */

- (void)refreshInFeedAd {
    [BFIOSDK refreshInFeedAd: adView AppID:YOUR_APP_ID adUnitID:YOUR_AD_UNIT_ID userGender:nil userAge:0 success:^(BFPrerollView *inFeedAd) {
        
		[adView resume]; // play video Ad
        
    } failure:^(NSError *error) {
        // error handling
    }];
    }
}

```

--

**Cell Re-use**  
When a user is scrolling through a feed of content, that content is generally expected not to change unless a "refresh" action occurs. We believe this also applies to ads. Because the AdColony SDK might provide a new ad upon each request for an `BFPrerollView`, you should store the In-Feed ads you request outside of your `UITableViewCell`s so that you can maintain consistency across cell reuse. You should associate each `BFPrerollView` with the `NSIndexPath` where it first appeared in your table view, so that you can reuse the ad view in the same place if that row happens to come back on screen. Since you typically add the `BFPrerollView` as a subview of a cell, you will want to remove it from the cell's subviews when that cell is being reused.

###Notes###
The is a minimal example, please make note of the detailed comments in the `BFPrerollView.h` header file. A sample app demonstrating the full functionality will be available shortly.

## Listening for Events
Optionally register for BFIO Ad events by adding your controller as an observer to the following SDK notifications:


#####BFAdInterstitialOpenedNotification
	Fires after interstitial view opens

#####BFAdInterstitialStartedNotification
	Fired after interstitial ad video starts playing

#####BFAdInterstitialCompletedNotification
    Fired when an ad video is completed

#####BFAdInterstitialClosedNotification
	Fired when an ad interstitial view is closed

#####BFAdPrerollStartedNotification
	Fired when a preroll ad has started
	
#####BFAdPrerollCompletedNotification
	Fired when a preroll ad has completed



## Check out the Examples

Also see the sample app 'BFIOSDKExample' included in the SDK download bundle. It contains clear examples on how to show an interstitial ad and register for events. 


##Support 
Have an issue? [Contact us](mailto:eric@beachfrontmedia.com) or [create an issue on GitHub](https://github.com/beachfront/beachfront-io-ios-sdk/issues)