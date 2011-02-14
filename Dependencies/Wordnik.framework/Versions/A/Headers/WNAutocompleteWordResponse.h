/*
 * Copyright Wordnik, Inc. 2010. All rights reserved.
 */

#import <Foundation/Foundation.h>

@interface WNAutocompleteWordResponse : NSObject {
@private
    /** The remaining number of results. */
    NSInteger _remainingResultCount;

    /** The total result count. */
    NSInteger _totalResultCount;

    /** The returned word strings. */
    NSArray *_wordStrings;
}

+ (id) responseWithWordStrings: (NSArray *) wordStrings 
              totalResultCount: (NSInteger) totalResultCount
          remainingResultCount: (NSInteger) remainingResultCount;

- (id) initWithWordStrings: (NSArray *) wordStrings 
          totalResultCount: (NSInteger) totalResultCount
      remainingResultCount: (NSInteger) remainingResultCount;

/** Matching word strings. */
@property(nonatomic, readonly) NSArray *wordStrings;

/**
 * The total number of autocomplete matches. Fewer matches may be available in this response.
 */
@property(nonatomic, readonly) NSInteger totalResultCount;

/**
 * The remaining number of autocomplete matches. Pagination of remaining results may be accomplished with
 * WNAutocompleteWordRequest::resultOffset.
 */
@property(nonatomic, readonly) NSInteger remainingResultCount;


@end

