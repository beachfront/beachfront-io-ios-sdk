//
//  BFFinalView.h
//  BFIOSDK
//
//  Created by Eric Turner on 6/5/13.
//  Copyright (c) 2013 Beachfront Media, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@class BFAdResponse;

@interface BFEndCardView : UIView

/**
 Returns an instance of a BFEndCardView.
 @param adResponse The json dictionary received from the server.
 */
- (id)initWithAdResponse:(BFAdResponse *)adResponse;

@end
