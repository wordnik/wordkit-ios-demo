/*
 * Copyright Wordnik, Inc. 2010. All rights reserved.
 */


#import <Foundation/Foundation.h>

#import <Wordnik/WNWord.h>
#import <Wordnik/WNSpellingSuggestion.h>

@interface WNWordResponse : NSObject {
@private
    /** The returned word record. */
    WNWord *_word;
    
    /** Alternative spelling suggestions as an ordered array of WNSpellingSuggestion instances. Will be empty
     * if alternative spelling suggestions were not either not requested or not available. */
    NSArray *_spellingSuggestions;
}

+ (id) responseWithWord: (WNWord *) word spellingSuggestions: (NSArray *) spellingSuggestions;
- (id) initWithWord: (WNWord *) word spellingSuggestions: (NSArray *) spellingSuggestions;

/** The returned word record. */
@property(nonatomic, readonly) WNWord *word;

/** Alternative spelling suggestions as an ordered array of WNSpellingSuggestion instances. Will be empty
 * if alternative spelling suggestions were not requested. */
@property(nonatomic, readonly) NSArray *spellingSuggestions;

@end
