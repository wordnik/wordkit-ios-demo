/*
 * Copyright Wordnik, Inc. 2010. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <Wordnik/WNConstants.h>

@interface WNRandomWordRequest : NSObject {
@private
    /** If YES, a dictionary definition is required. */
    BOOL _requireDictionaryDefinition;

    /** Maximum result count, or WNUnlimitedResultLength to return the maximum number permitted by the server. */
    NSInteger _maxResultCount;
}

+ (id) request;
+ (id) requestWithDictionaryDefinitionRequired: (BOOL) requireDictionaryDefinition
                                maxResultCount: (NSInteger) maxResultCount;

- (id) init;
- (id) initWithDictionaryDefinitionRequired: (BOOL) requireDictionaryDefinition
                             maxResultCount: (NSInteger) maxResultCount;

/** The maximum number of results to return, or WNUnlimitedResultLength to return the maximum number permitted by the server. */
@property(nonatomic, readonly) NSInteger maxResultCount;

/** If YES, only words with an available dictionary definition will be returned. */
@property(nonatomic, readonly) BOOL dictionaryDefinitionRequired;

@end
