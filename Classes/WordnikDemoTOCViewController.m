/*
 * Copyright Wordnik, Inc. 2010. All rights reserved.
 */

#import "WordnikDemoTOCViewController.h"

@interface WordnikDemoTOCViewController () <UITableViewDelegate, UITableViewDataSource>
- (void) loadToc;
@end

/**
 * Provides a Table of Contents for the demo application.
 */
@implementation WordnikDemoTOCViewController

@synthesize delegate = _delegate;

- (id) init {
	if ((self = [super initWithNibName: @"WordnikDemoTOCViewController" bundle: nil]) == nil)
		return nil;	
    
    [self loadToc];
    
	return self;
}

/**
 * @internal
 * Discard any references to subviews of the primary managed view. This method
 * is called from both -viewDidUnload and -dealloc, and ensures that the instance does
 * not maintain references to subview elements after the primary view has been discarded.
 */
- (void) discardSubviews {
    [_tableView release];
    _tableView = nil;
}

- (void) dealloc {
    [self discardSubviews];
    
    [super dealloc];
}

- (void) viewDidLoad {
    [super viewDidLoad];

    _tableView.delegate = self;
    _tableView.dataSource = self;
    [_tableView reloadData];
}

- (void) viewDidUnload {
    [self discardSubviews];
}

- (BOOL) shouldAutorotateToInterfaceOrientation: (UIInterfaceOrientation) interfaceOrientation {
    return YES;
}

static int tocSort (id obj1, id obj2, void *context) {
    NSString *string1 = obj1;
    NSString *string2 = obj2;
    return [string1 compare: string2 options: NSNumericSearch];
}

/*
 * Load the ToC data from our main bundle.
 */
- (void) loadToc {
    NSFileManager *fm = [NSFileManager defaultManager];

    NSString *htmlPath = [[NSBundle mainBundle] pathForResource: @"html" ofType: nil];
    NSMutableArray *titles = [NSMutableArray array];
    NSMutableArray *paths = [NSMutableArray array];
    
    /* Load the index data */
    NSString *title = [NSString stringWithContentsOfFile: [htmlPath stringByAppendingPathComponent: @"title.txt"]
                                                encoding: NSUTF8StringEncoding
                                                   error: NULL];
    NSString *path = [htmlPath stringByAppendingPathComponent: @"index.html"];

    [titles addObject: title];
    [paths addObject: path];

    /* Fetch the top-level directory listing, sort it numerically */
    NSArray *contents = [fm contentsOfDirectoryAtPath: htmlPath error: NULL];
    contents = [contents sortedArrayUsingFunction: tocSort context: NULL];

    for (NSString *subdir in contents) {
        /* Create the absolute path */
        subdir = [htmlPath stringByAppendingPathComponent: subdir];

        /* Skip directories that don't have a title */
        NSString *titlePath = [subdir stringByAppendingPathComponent: @"title.txt"];
        if (![fm fileExistsAtPath: titlePath])
            continue;

        /* Load title/path data */
        title = [NSString stringWithContentsOfFile: titlePath
                                          encoding: NSUTF8StringEncoding
                                             error: NULL];
        path = [subdir stringByAppendingPathComponent: @"index.html"];
        
        [titles addObject: title];
        [paths addObject: path];
    }

    assert(_titles == nil && _paths == nil);
    _titles = [titles retain];
    _paths = [paths retain];
}

// from UITableViewDataSource protocol
- (NSInteger) tableView: (UITableView *) tableView numberOfRowsInSection: (NSInteger) section {
    return [_titles count];
}

// from UITableViewDataSource protocol
- (UITableViewCell *) tableView: (UITableView *) tableView cellForRowAtIndexPath: (NSIndexPath *) indexPath {
    static NSString *reuseIdentifier = @"TOCCell";

    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier: reuseIdentifier];
    if (cell == nil)
        cell = [[[UITableViewCell alloc] initWithStyle: UITableViewCellStyleDefault reuseIdentifier: reuseIdentifier] autorelease];
    
    cell.textLabel.text = [_titles objectAtIndex: indexPath.row];
    cell.accessoryType = UITableViewCellAccessoryDetailDisclosureButton;

    return cell;
}

- (void) tableView: (UITableView *) tableView didSelectRowAtIndexPath: (NSIndexPath *) indexPath {
    [tableView deselectRowAtIndexPath: indexPath animated: YES];
    [_delegate tocController: self didSelectPath: [_paths objectAtIndex: indexPath.row]];
}


@end
