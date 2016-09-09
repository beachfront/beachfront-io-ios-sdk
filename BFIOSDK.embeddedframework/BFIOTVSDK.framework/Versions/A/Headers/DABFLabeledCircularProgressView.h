//
//  DALabeledCircularProgressView.h
//  DACircularProgressExample
//
//  Created by Josh Sklar on 4/8/14.
//  Copyright (c) 2014 Shout Messenger. All rights reserved.
//

#import "DABFCircularProgressView.h"

/**
 @class DALabeledCircularProgressView
 
 @brief Subclass of DACircularProgressView that adds a UILabel.
 */
@interface DABFLabeledCircularProgressView : DABFCircularProgressView

/**
 UILabel placed right on the DACircularProgressView.
 */
@property (strong, nonatomic) UILabel *progressLabel;

@end
