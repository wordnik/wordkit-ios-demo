/*
 * Copyright Wordnik, Inc. 2010. All rights reserved.
 */

#import "WordnikDemoAppViewController.h"
#import "WordnikDemoTOCViewController.h"

#import <WordnikUI/WordnikUI.h>

@interface WordnikDemoAppViewController () <UIWebViewDelegate, UIPopoverControllerDelegate, WordnikDemoTOCViewControllerDelegate, WNDefinitionViewControllerDelegate>
- (void) loadHTMLFromPath: (NSString *) path;
- (void) didPressTableOfContentsButton: (id) sender;
@end

/**
 * View Controller that manages the primary documentation view.
 */
@implementation WordnikDemoAppViewController

/**
 * Initialize with the provided Wordnik network client.
 *
 * @param client Wordnik client.
 */
- (id) initWithWordnikClient: (WNClient *) client {
	if ((self = [super initWithNibName: @"WordnikDemoAppViewController" bundle: nil]) == nil)
		return nil;	

    _client = [client retain];
    _dataSource = [[WNWordNetworkDataSource alloc] initWithWordnikClient: client];
    
	return self;
}

/**
 * @internal
 * Discard any references to subviews of the primary managed view. This method
 * is called from both -viewDidUnload and -dealloc, and ensures that the instance does
 * not maintain references to subview elements after the primary view has been discarded.
 */
- (void) discardSubviews {
    _wordnikWebView.delegate = nil;
    [_wordnikWebView release];
    _wordnikWebView = nil;
    
    [_tableOfContentsButton release];
    _tableOfContentsButton = nil;
    
    _tableOfContentsPopover.delegate = nil;
    [_tableOfContentsPopover release];
    _tableOfContentsPopover = nil;
}

- (void) dealloc {
    [self discardSubviews];

    [_client release];
    [_dataSource release];
    
    [super dealloc];
}

// property setter
- (void) setClient: (WNClient *) client {
    [_client release];
    _client = [client retain];

    [_dataSource release];
    _dataSource = [[WNWordNetworkDataSource alloc] initWithWordnikClient: client];
}

// property getter
- (WNClient *) client {
    return _client;
}


// from UIViewController
- (BOOL) shouldAutorotateToInterfaceOrientation: (UIInterfaceOrientation) interfaceOrientation {
    return YES;
}

- (BOOL) canPerformAction: (SEL) action withSender: (id) sender {
    if (![self respondsToSelector: action])
        return NO;
    
    // TODO - Get selection info from web view

    return YES;
}

- (void) definitionViewControllerDidRequestClose: (WNDefinitionViewController *) viewController {
    [self dismissModalViewControllerAnimated: YES];
}

- (void) wordnikLookup: (id) sender {
    /* Fetch the current selection and its pixel location */
    NSString *selected = [_wordnikWebView stringByEvaluatingJavaScriptFromString: @"window.getSelection().toString();"];
    NSString *positionString = [_wordnikWebView stringByEvaluatingJavaScriptFromString:
                                @"(function () {\n"
                                    // Fetch the selection
                                    "var sel = window.getSelection();"
                                    "var node = sel.anchorNode;"

                                    // Insert a dummy node that we'll use to find the selection position
                                    "var range = sel.getRangeAt(0);"
                                    "var dummyNode = document.createElement(\"span\");"
                                    "range.insertNode(dummyNode);"

                                    // Define the functions we'll use to calculate the dummy node's position
                                    "function Point(x, y) {"
                                        "this.x = x;"
                                        "this.y = y;"
                                    "}"

                                    "function getPoint (o) {"
                                        "var oX = 0;"
                                        "var oY = 0;"
                                        "if (o.offsetParent) {"
                                            "do {"
                                                "oX += o.offsetLeft;"
                                                "oY += o.offsetTop;"
                                                "o=o.offsetParent;"
                                            "} while (o)"
                                        "} else if (o.x) {"
                                            "oX += o.x;"
                                            "oY += o.y;"
                                        "}"
                                        "return new Point(oX, oY);"
                                    "}"

                                    // Get the dummy node's position and drop the node
                                    "var p = getPoint(dummyNode);"
                                    "dummyNode.parentNode.removeChild(dummyNode);"
                                
                                    // Offset for the current window offset.
                                    "p.x -= window.pageXOffset;"
                                    "p.y -= window.pageYOffset;"

                                    // TODO - determine the text line height and offset the arrow accordingly?

                                    // Return the coordinates as a CGPointFromString() compatible {x, y} string
                                    "return \"{\" + p.x + \", \" + p.y + \"}\";"
                                "})();"];
    CGPoint position = CGPointFromString(positionString);
    position = [self.view convertPoint: position fromView: _wordnikWebView];

    /* Create our view controllers */
    WNDefinitionViewController *vc = [[[WNDefinitionViewController alloc] initWithWordString: selected
                                                                                  dataSource: _dataSource] autorelease];
    vc.delegate = self;

    UINavigationController *navVC = [[[UINavigationController alloc] initWithRootViewController: vc] autorelease];
    navVC.navigationBar.barStyle = UIBarStyleBlack;

    if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone) {
        [self presentModalViewController: navVC animated: YES];

    } else if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) {
        UIPopoverController *popover = [[UIPopoverController alloc] initWithContentViewController: navVC];
        popover.popoverContentSize = CGSizeMake(320, 480);

        // TODO - position correctly in web view
        [popover presentPopoverFromRect: CGRectMake(position.x, position.y, 0.0f, 0.0f) 
                                 inView: self.view
               permittedArrowDirections: UIPopoverArrowDirectionAny 
                               animated: YES];
    }
}


// from UIViewController
- (void) viewDidLoad {
    [super viewDidLoad];
	_wordnikWebView.delegate = self;

    /* Fetch the local HTML path */
    NSString *path = [[NSBundle mainBundle] pathForResource: @"index.html" ofType: nil inDirectory: @"html"];
    [self loadHTMLFromPath: path];

    /* Setup the 'table of contents' button */
    _tableOfContentsButton.target = self;
    _tableOfContentsButton.action = @selector(didPressTableOfContentsButton:);
    
    if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone) {
        _tableOfContentsButton.title = @"Contents";
    }

}

// from UIViewController
- (void) viewDidUnload {
    [self discardSubviews];
}

// from UIWebViewDelegate protocol
- (BOOL) webView: (UIWebView *) webView shouldStartLoadWithRequest: (NSURLRequest *) request navigationType: (UIWebViewNavigationType) navigationType {
    NSURL *url = [request URL];

    /* If the URL references an HTTP or HTTPS server, let Safari handle it */
    NSString *scheme = [url scheme];
    if ([scheme isEqual: @"http"] || [scheme isEqual: @"https"]) {
        [[UIApplication sharedApplication] openURL: url];
        return NO;
    }

    /* Default behavior */
    return YES;
}

- (void) loadHTMLFromPath: (NSString *) path {
    NSURL *url = [NSURL fileURLWithPath: path];
    
    /* Submit the request to our web view. */
    NSURLRequest *requestObj = [NSURLRequest requestWithURL: url];
    [_wordnikWebView loadRequest: requestObj];
}

- (void) dismissTOC {
    if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) {
        [_tableOfContentsPopover dismissPopoverAnimated: YES];
        [self popoverControllerDidDismissPopover: _tableOfContentsPopover];
    } else {
        [self dismissModalViewControllerAnimated: YES];
    }
}

/*
 * Shows the 'table of contents' popover.
 */
- (void) didPressTableOfContentsButton: (id) sender {
    /* If a popover exists, dismiss it. */
    if (_tableOfContentsPopover != nil) {
        [self dismissTOC];
        return;
    }

    /* Load the TOC controller */
    WordnikDemoTOCViewController *vc = [[[WordnikDemoTOCViewController alloc] init] autorelease];
    vc.delegate = self;

    /* On the iPad, display a pop-over. On the iPhone, push a modal view controller */
    if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) {
        _tableOfContentsPopover = [[UIPopoverController alloc] initWithContentViewController: vc];
        _tableOfContentsPopover.delegate = self;
        _tableOfContentsPopover.popoverContentSize = CGSizeMake(320, 480);
        [_tableOfContentsPopover presentPopoverFromBarButtonItem: _tableOfContentsButton
                                 permittedArrowDirections: UIPopoverArrowDirectionAny animated: YES];
    } else {
        vc.modalTransitionStyle = UIModalTransitionStyleFlipHorizontal;
        [self presentModalViewController: vc animated: YES];
    }
}

// from UIPopoverControllerDelegate protocol
- (void) popoverControllerDidDismissPopover: (UIPopoverController *) popoverController {
    [_tableOfContentsPopover release];
    _tableOfContentsPopover = nil;
}

// from WordnikDemoTOCViewControllerDelegate protocol
- (void) tocController: (WordnikDemoTOCViewController *) controller didSelectPath: (NSString *) path {
    [self loadHTMLFromPath: path];

    [self dismissTOC];
}

@end
