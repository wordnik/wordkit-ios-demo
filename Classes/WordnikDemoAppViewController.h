/*
 * Copyright Wordnik, Inc. 2010. All rights reserved.
 */

#import <UIKit/UIKit.h>

#import <Wordnik/Wordnik.h>
#import <WordnikUI/WordnikUI.h>

@interface WordnikDemoAppViewController : UIViewController {
@private
    /** Main content is displayed in a webview */
    IBOutlet UIWebView *_wordnikWebView;
    
    /** Navigation button to access Table of Contents */
    IBOutlet UIBarButtonItem *_tableOfContentsButton;
    
    /** Table of Contents popover view */
    UIPopoverController *_tableOfContentsPopover;
    
    /** Network client. */
    WNClient *_client;

    /** Wordnik data source. */
    id<WNWordDataSource> _dataSource;
}

- (id) initWithWordnikClient: (WNClient *) client;

/** The network client. */
@property(nonatomic, retain) WNClient *client;

@end

