//
//  BFHTTPRequestOperation.h
//  BFIOSDK
//
//  Created by Sumeru Chatterjee on 5/8/13.
//  Copyright (c) 2013 Beachfront Media, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BFHTTPRequestOperation : NSOperation
/**
 Creates and returns an `BFHTTPRequestOperation` object and sets the specified success and failure callbacks.

 @param urlRequest The request object to be loaded asynchronously during execution of the operation
 @param success A block object to be executed when the operation finishes successfully. This block has no return value and takes three arguments: the request sent from the client, the response received from the server, and the response object created from the response data of request.
 @param failure A block object to be executed when the operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data as JSON. This block has no return value and takes three arguments: the request sent from the client, the response received from the server, and the error describing the network or parsing error that occurred.

 @return A new connection operation
 */
+ (instancetype)startOperationWithRequest:(NSURLRequest *)urlRequest
				  success:(void (^)(NSURLRequest *request, NSHTTPURLResponse *response, id responseObject))success
				  failure:(void (^)(NSURLRequest *request, NSHTTPURLResponse *response, NSError *error))failure;
/**
 Creates and returns an `BFHTTPRequestOperation` object and sets the specified success and failure callbacks.

 @param urlRequest The request object to be loaded asynchronously during execution of the operation
 @param timesRetry The number of times we should try to retry this in case of failure
 @param success A block object to be executed when the operation finishes successfully. This block has no return value and takes three arguments: the request sent from the client, the response received from the server, and the response object created from the response data of request.
 @param failure A block object to be executed when the operation finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data as JSON. This block has no return value and takes three arguments: the request sent from the client, the response received from the server, and the error describing the network or parsing error that occurred.

 @return A new connection operation
 */
+ (instancetype)startOperationWithRequest:(NSURLRequest *)urlRequest
			       timesRetry:(NSInteger)timesRetry
				  success:(void (^)(NSURLRequest *request, NSHTTPURLResponse *response, id responseObject))success
				  failure:(void (^)(NSURLRequest *request, NSHTTPURLResponse *response, NSError *error))failure;
/**
 Initializes and returns a newly allocated operation object with a url connection configured with the specified url request.

 This is the designated initializer.

 @param urlRequest The request object to be used by the operation connection.
 */
- (id)initWithRequest:(NSURLRequest *)urlRequest;
/**
 The request used by the operation's connection.
 */
@property (readonly, nonatomic, strong) NSURLRequest *request;
/**
 The last response received by the operation's connection.
 */
@property (readonly, nonatomic, strong) NSHTTPURLResponse *response;
/**
 The data received during the request.
 */
@property (readonly, nonatomic, strong) NSData *responseData;
/**
 The error, if any, that occurred in the lifecycle of the request.
 */
@property (readonly, nonatomic, strong) NSError *error;

/**
 Sets the `completionBlock` property with a block that executes either the specified success or failure block, depending on the state of the request on completion. If `error` returns a value, which can be caused by an unacceptable status code or content type, then `failure` is executed. Otherwise, `success` is executed.
 
 This method should be overridden in subclasses in order to specify the response object passed into the success block.
 
 @param success The block to be executed on the completion of a successful request. This block has no return value and takes two arguments: the receiver operation and the object constructed from the response data of the request.
 @param failure The block to be executed on the completion of an unsuccessful request. This block has no return value and takes two arguments: the receiver operation and the error that occurred during the request.
 */
- (void)setCompletionBlockWithSuccess:(void (^)(BFHTTPRequestOperation *operation, id responseObject))success
                              failure:(void (^)(BFHTTPRequestOperation *operation, NSError *error))failure;

@end
