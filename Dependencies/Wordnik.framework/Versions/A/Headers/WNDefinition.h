/*
 * Copyright Wordnik, Inc. 2010. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <Wordnik/WNPartOfSpeech.h>
#import <Wordnik/WNDefinitionCitation.h>
#import <Wordnik/WNDefinitionLabel.h>

@interface WNDefinition : NSObject {
@private
    /** The canonical wordnik identifier for this definition. */
    NSString *_wordnikId;

    /**
     * Head word. This is the word that should serve as the heading for this definition's
     * entry in the dictionary.
     */
    NSString *_headWord;

    /** The definition text. */
    NSString *_text;
    
    /** The optional extended definition text. If available, may be used in favor of the definition text
     * in contexts where a longer, expanded definition is suitable. */
    NSString *_extendedText;

    /** This definition's part of speech */
    WNPartOfSpeech *_partOfSpeech;
    
    /** The ordered array of citations for this definition, as an array of WNDefinitionCitation instances. */
    NSArray *_citations;

    /** The array of labels for this definition, as an array of WNDefinitionLabel instances. */
    NSArray *_labels;
}

+ (id) definitionWithWordnikId: (NSString *) wordnikId
                      headWord: (NSString *) headWord 
                          text: (NSString *) text 
                  extendedText: (NSString *) extendedText
                  partOfSpeech: (WNPartOfSpeech *) partOfSpeech
                     citations: (NSArray *) citations
                        labels: (NSArray *) labels;

- (id) initWithWordnikId: (NSString *) wordnikId
                headWord: (NSString *) headWord 
                    text: (NSString *) text 
            extendedText: (NSString *) extendedText
            partOfSpeech: (WNPartOfSpeech *) partOfSpeech
               citations: (NSArray *) citations
                  labels: (NSArray *) labels;

/** The canonical wordnik identifier for this definition. */
@property(nonatomic, readonly) NSString *wordnikId;

/**
 * Head word. This is the word that should serve as the heading for this definition's
 * entry in the dictionary.
 */
@property(nonatomic, readonly) NSString *headWord;

/** The definition text. */
@property(nonatomic, readonly) NSString *text;

/** The optional extended definition text. If not nil, this property may be used in favor of the definition text
 * in contexts where a longer, expanded definition is suitable. */
@property(nonatomic, readonly) NSString *extendedText;

/** This definition's part of speech */
@property(nonatomic, readonly) WNPartOfSpeech *partOfSpeech;

/** The ordered array of citations for this definition, as an array of WNDefinitionCitation instances. If no citations
 * are available, this array will be empty. */
@property(nonatomic, readonly) NSArray *citations;

/** The array of labels for this definition, as an array of WNDefinitionLabel instances. If no labels are available,
 * this array will be empty. */
@property(nonatomic, readonly) NSArray *labels;

@end
