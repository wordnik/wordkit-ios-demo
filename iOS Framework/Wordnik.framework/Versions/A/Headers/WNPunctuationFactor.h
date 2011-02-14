/*
 * Copyright Wordnik, Inc. 2010. All rights reserved.
 */

#import <Foundation/Foundation.h>

@interface WNPunctuationFactor : NSObject {
@private
    /** Number of times the word occurs with an exclamation point. */
    NSInteger _exclamationPointCount;
    
    /** Number of times the word occurs with a period. */
    NSInteger _periodCount;
    
    /** Number of times the word occurs with a question mark. */
    NSInteger _questionMarkCount;
}

+ (id) punctuationFactorWithExclamationPointCount: (NSInteger) exclamationPointCount
                                      periodCount: (NSInteger) periodCount 
                                questionMarkCount: (NSInteger) questionMarkCount;

- (id) initWithExclamationPointCount: (NSInteger) exclamationPointCount
                         periodCount: (NSInteger) periodCount 
                   questionMarkCount: (NSInteger) questionMarkCount;

/** Number of times the word occurs with an exclamation point. */
@property(nonatomic, readonly) NSInteger exclamationPointCount;

/** Number of times the word occurs with a period. */
@property(nonatomic, readonly) NSInteger periodCount;

/** Number of times the word occurs with a question mark. */
@property(nonatomic, readonly) NSInteger questionMarkCount;

@end
