/*
 * Copyright Wordnik, Inc. 2010. All rights reserved.
 */

#import "WordnikDemoAppAppDelegate.h"
#import "WordnikDemoAppViewController.h"

/* Wordnik API key. */
#define API_KEY @"28cdb697b27e0126b800f0d60780c352c7d1f093d8f807010"

@implementation WordnikDemoAppAppDelegate

#pragma mark -
#pragma mark Application lifecycle

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    /* Configure the singleton UIMenuController, adding the Wordnik menu item. */
    {
        UIMenuItem *wordnikItem = [[[UIMenuItem alloc] initWithTitle: @"Look Up" action: @selector(wordnikLookup:)] autorelease];
        UIMenuController *controller = [UIMenuController sharedMenuController];
        
        /* Create a new menu item array, preserving the current items */
        NSMutableArray *items = [NSMutableArray array];
        if (controller.menuItems != nil)
            [items addObjectsFromArray: controller.menuItems];

        [items addObject: wordnikItem];
        
        /* Set the global set of menu items. */
        controller.menuItems = items;
    }
    
    /* Set up our network client. */
    WNClientConfig *config = [WNClientConfig configWithAPIKey: API_KEY];
    WNClient *client = [[[WNClient alloc] initWithClientConfig: config] autorelease];
    _viewController.client = client;

    /* Set up our root view controller */
    [_window addSubview: _viewController.view];
    [_window makeKeyAndVisible];

	return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    /*
     Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
     Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
     */
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    /*
     Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
     */
}


- (void)applicationWillTerminate:(UIApplication *)application {
    /*
     Called when the application is about to terminate.
     See also applicationDidEnterBackground:.
     */
}


#pragma mark -
#pragma mark Memory management

- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application {
    /*
     Free up as much memory as possible by purging cached data objects that can be recreated (or reloaded from disk) later.
     */
}


- (void)dealloc {
    [_window release];
    [super dealloc];
}


@end
