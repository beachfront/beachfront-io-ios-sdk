
# Guide
Beachfront.io is the easist way monetize your app using Interstitial and Preroll Video Ads. This document shows you how to integrate Beachfront.io into your iOS app.



## What You'll Need
* Xcode version 4.5 or higher
* An iOS app targeting at least iOS version 5.1


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