/*
 * Copyright Wordnik, Inc. 2010. All rights reserved.
 */

#import <Foundation/Foundation.h>


@interface WNSpellingSuggestion : NSObject <NSCopying> {
@private
    /** The suggested word. */
    NSString *_wordString;
}

+ (id) suggestionWithWordString: (NSString *) wordString;
- (id) initWithWordString: (NSString *) wordString;

/** A suggested alternative word. */
@property(nonatomic, readonly) NSString *wordString;

@end
