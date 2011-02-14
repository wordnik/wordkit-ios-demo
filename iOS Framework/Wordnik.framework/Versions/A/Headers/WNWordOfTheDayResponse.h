/*
 * Copyright Wordnik, Inc. 2010. All rights reserved.
 */

#import <Foundation/Foundation.h>


@interface WNWordOfTheDayResponse : NSObject {
@private
    /** The word string. */
    NSString *_wordString;
    
    /** The date the entry was published. */
    NSDate *_publishDate;

    /** An ordered array of definition strings, formatted for display. */
    NSArray *_definitionStrings;

    /** An ordered array of usage examples, formatted for display. */
    NSArray *_usageExampleStrings;

    /** An ordered array of notes, formatted for display. */
    NSArray *_noteStrings;
}

+ (id) responseWithWordString: (NSString *) wordString
                  publishDate: (NSDate *) publishDate
            definitionStrings: (NSArray *) definitionStrings
          usageExamplestrings: (NSArray *) usageExampleStrings
                  noteStrings: (NSArray *) noteStrings;

- (id) initWithWordString: (NSString *) wordString
              publishDate: (NSDate *) publishDate
        definitionStrings: (NSArray *) definitionStrings
      usageExamplestrings: (NSArray *) usageExampleStrings
              noteStrings: (NSArray *) noteStrings;

/** The word string. */
@property(nonatomic, readonly) NSString *wordString;

/** The date the entry was published. */
@property(nonatomic, readonly) NSDate *publishDate;

/** An ordered array of definition strings, formatted for display. */
@property(nonatomic, readonly) NSArray *definitionStrings;

/** An ordered array of usage examples, formatted for display. */
@property(nonatomic, readonly) NSArray *usageExampleStrings;

/** An ordered array of notes, formatted for display. */
@property(nonatomic, readonly) NSArray *noteStrings;

@end
