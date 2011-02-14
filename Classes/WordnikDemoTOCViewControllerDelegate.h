/*
 * Copyright Wordnik, Inc. 2010. All rights reserved.
 */


#import <UIKit/UIKit.h>

@class WordnikDemoTOCViewController;

/**
 * Delegates of WordnikDemoTOCViewController must implement the WordnikDemoTOCViewControllerDelegate protocol.
 */
@protocol WordnikDemoTOCViewControllerDelegate

/**
 * Called when a TOC section is selected.
 *
 * @param controller Sending controller.
 * @param path Selected HTML path.
 */
- (void) tocController: (WordnikDemoTOCViewController *) controller didSelectPath: (NSString *) path;

@end
