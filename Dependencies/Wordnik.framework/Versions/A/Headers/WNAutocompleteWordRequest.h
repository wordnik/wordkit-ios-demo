/*
 * Copyright Wordnik, Inc. 2010. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 * @ingroup globals
 *
 * Supported collations for WNAutocompleteWordRequest.
 */
typedef enum {
    /** Order the results alphabetically. */
    WNAutocompleteWordCollationAlphabetical = 0,

    /** Order the results by frequency descending -- that is, highest frequency results will be listed
     * first */
    WNAutocompleteWordCollationFrequencyDescending = 1
} WNAutocompleteWordCollation;


@interface WNAutocompleteWordRequest : NSObject {
@private
    /** */
    NSString *_wordFragment;

    /** If YES, a dictionary definition is required. */
    BOOL _dictionaryDefinitionRequired;

    /** Maximum result count, or WNUnlimitedResultLength to return the maximum number permitted by the server. */
    NSInteger _maxResultCount;

    /** The offset of the results to be returned. Can be used to paginate autocomplete suggestions. */
    NSInteger _resultOffset;

    /** The result collation. */
    WNAutocompleteWordCollation _resultCollation;
}

+ (id) requestWithWordFragment: (NSString *) wordFragment maxResultCount: (NSInteger) maxResultCount;
- (id) initWithWordFragment: (NSString *) wordFragment maxResultCount: (NSInteger) maxResultCount;

+ (id) requestWithWordFragment: (NSString *) wordFragment
                maxResultCount: (NSInteger) maxResultCount 
                  resultOffset: (NSInteger) resultOffset
               resultCollation: (WNAutocompleteWordCollation) resultCollation
  dictionaryDefinitionRequired: (BOOL) dictionaryDefinitionRequired;

- (id)  initWithWordFragment: (NSString *) wordFragment
              maxResultCount: (NSInteger) maxResultCount 
                resultOffset: (NSInteger) resultOffset
             resultCollation: (WNAutocompleteWordCollation) resultCollation
dictionaryDefinitionRequired: (BOOL) dictionaryDefinitionRequired;

/** The word fragment to be autocompleted. A single-character '*' wild-card may be included; 't*e' would match 'the'. */
@property(nonatomic, readonly) NSString *wordFragment;

/** The maximum number of results to return, or WNUnlimitedResultLength to return the maximum number permitted by the server. */
@property(nonatomic, readonly) NSInteger maxResultCount;

/** The offset of the results to be returned. Can be used to paginate autocomplete suggestions. */
@property(nonatomic, readonly) NSInteger resultOffset;

/** The collation to use for the returned results. */
@property(nonatomic, readonly) WNAutocompleteWordCollation resultCollation;

/** If YES, only words with an available dictionary definition will be returned. */
@property(nonatomic, readonly) BOOL dictionaryDefinitionRequired;

@end
