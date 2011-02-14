/*
 * Copyright Wordnik, Inc. 2010. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <Wordnik/WNDefinitionList.h>
#import <Wordnik/WNExampleSentence.h>
#import <Wordnik/WNRelatedWordList.h>
#import <Wordnik/WNUsageFrequencyTimeline.h>
#import <Wordnik/WNPunctuationFactor.h>
#import <Wordnik/WNBigram.h>

@interface WNWord : NSObject {
@private
    /** The word's string value. */
    NSString *_wordString;

    /** The word's definition list. */
    NSArray *_definitionLists;

    /** Ordered array of bigram phrases. */
    NSArray *_bigrams;
    
    /** Related word list. */
    WNRelatedWordList *_relatedWordList;

    /** Ordered array of example sentences. */
    NSArray *_exampleSentences;

    /** Word usage frequency timeline. */
    WNUsageFrequencyTimeline *_frequencyTimeline;
    
    /** Text pronunciations. */
    NSArray *_pronunciations;

    /** Punctuation factor. */
    WNPunctuationFactor *_punctuationFactor;
}

+ (id) wordWithWordString: (NSString *) wordString;
+ (id) wordWithWordString: (NSString *) wordString 
          definitionLists: (NSArray *) definitionLists
         exampleSentences: (NSArray *) exampleSentences
          relatedWordList: (WNRelatedWordList *) relatedWordList
   usageFrequencyTimeline: (WNUsageFrequencyTimeline *) frequencyTimeline
       textPronunciations: (NSArray *) textPronunciations
        punctuationFactor: (WNPunctuationFactor *) punctuationFactor
                  bigrams: (NSArray *) bigrams;

- (id) initWithWordString: (NSString *) wordString;
- (id) initWithWordString: (NSString *) wordString 
          definitionLists: (NSArray *) definitionLists
         exampleSentences: (NSArray *) exampleSentences
          relatedWordList: (WNRelatedWordList *) relatedWordList
   usageFrequencyTimeline: (WNUsageFrequencyTimeline *) frequencyTimeline
       textPronunciations: (NSArray *) textPronunciations
        punctuationFactor: (WNPunctuationFactor *) punctuationFactor
                  bigrams: (NSArray *) bigrams;

- (WNWord *) wordByAppendingElementsFromWord: (WNWord *) otherWord;

/** The word's string value. */
@property(nonatomic, readonly) NSString *wordString;

/** The word's definition lists, if available. If not available, this property will be nil. */
@property(nonatomic, readonly) NSArray *definitionLists;

/** The word's associated bigram phrases as an ordered array of WNBigram instances, if available. If not available, this
 * property will be nil. */
@property(nonatomic, readonly) NSArray *bigrams;

/** Example sentences as an ordered array of WNExampleSentence instances, if available. If not available, this property
 * will be nil. */
@property(nonatomic, readonly) NSArray *exampleSentences;

/** Related word list, if available. If not available, this property will be nil. */
@property(nonatomic, readonly) WNRelatedWordList *relatedWordList;

/** Word usage frequency timeline, if available. If not available, this property will be nil. */
@property(nonatomic, readonly) WNUsageFrequencyTimeline *usageFrequencyTimeline;

/** Text pronunciations as an array of WNTextPronunciation instances, if available. If not available, this property will be nil. */
@property(nonatomic, readonly) NSArray *textPronunciations;

/** Punctuation factor for this word, if available. If not available, this property will be nil. */
@property(nonatomic, readonly) WNPunctuationFactor *punctuationFactor;

@end
