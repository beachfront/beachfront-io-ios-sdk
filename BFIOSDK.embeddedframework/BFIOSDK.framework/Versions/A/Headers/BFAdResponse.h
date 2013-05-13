//
//  BFAdResponse.h
//  BFIOSDK
//
//  Created by Todd Kuehnl on 5/7/13.
//  Copyright (c) 2013 Beachfront Media, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum{
    BFAdResponseResultSuccess,
    BFAdResponseResultFailure,
}BFAdResponseResult;

@interface BFAdResponse : NSObject
/**
 Initializes and returns a newly allocated  BFAdResponse Object
 
 This is the designated initializer.
 
 @param dictionary The json dictionary received from the server
 */
- (id)initWithJSONDictionary:(NSDictionary *)dictionary;
/**
 The result of the response.
 */
@property (readonly, nonatomic)         BFAdResponseResult result;
/**
 The urls for tracking click-through
 */
@property (readonly, nonatomic, strong) NSArray *clickThrough;
/**
 The urls of media file/files
 */
@property (readonly, nonatomic, strong) NSArray *mediaFiles;
/**
 The urls for tracking start of advertisement
 */
@property (readonly, nonatomic, strong) NSArray *start;
/**
 The urls for tracking an impression
 */
@property (readonly, nonatomic, strong) NSArray *impression;
/**
 The urls for tracking the completion of first quarter of advertisement.
 */
@property (readonly, nonatomic, strong) NSArray *firstQuartile;
/**
 The urls for tracking the completion of half of advertisement.
 */
@property (readonly, nonatomic, strong) NSArray *midPoint;
/**
 The urls for tracking the completion of three quarters of advertisement.
 */
@property (readonly, nonatomic, strong) NSArray *thirdQuartile;
/**
 The urls for tracking the completion of advertisement.
 */
@property (readonly, nonatomic, strong) NSArray *complete;
/**
 The urls for tracking the clicks on advertisement.
 */
@property (readonly, nonatomic, strong) NSArray *clickTracking;
/**
 The duration of the advertisement.
 */
@property (readonly, nonatomic)         NSInteger duration;
@end
