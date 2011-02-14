/*
 * Copyright Wordnik, Inc. 2010. All rights reserved.
 */

#import <UIKit/UIKit.h>

@class WordnikDemoAppViewController;

@interface WordnikDemoAppAppDelegate : NSObject <UIApplicationDelegate> {
    IBOutlet UIWindow *_window;
    IBOutlet WordnikDemoAppViewController *_viewController;
}

@end

