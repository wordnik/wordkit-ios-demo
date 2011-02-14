/*
 * Copyright Wordnik, Inc. 2010. All rights reserved.
 */

#import <UIKit/UIKit.h>

#import "WordnikDemoTOCViewControllerDelegate.h"

@interface WordnikDemoTOCViewController : UIViewController {
@private
    /** ToC Table */
    IBOutlet UITableView *_tableView;

    /** ToC titles */
    NSArray *_titles;

    /** ToC paths */
    NSArray *_paths;

    /** Non-retained delegate. */
    id<WordnikDemoTOCViewControllerDelegate> _delegate;
}

/** Table of contents delegate. */
@property(nonatomic, assign) id<WordnikDemoTOCViewControllerDelegate> delegate;

@end
