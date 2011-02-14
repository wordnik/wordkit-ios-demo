/*
 * Copyright Wordnik, Inc. 2010. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 * @defgroup classes Class Reference
 */

/**
 * @internal
 * @ingroup classes
 * @defgroup internal_api Wordnik Internal
 *
 * A set of private APIs that are accessible to other Wordnik libraries.
 */

/**
 * @ingroup classes
 * @defgroup classes_data Word Data
 *
 * Wordnik data classes.
 */

/**
 * @defgroup functions Functions Reference
 */

/**
 * @defgroup types Data Types Reference
 */

/**
 * @defgroup constants Constants Reference
 */

/**
 * @defgroup enums Enumerations
 * @ingroup constants
 */

/**
 * @defgroup globals Global Variables
 * @ingroup constants
 */

/**
 * @defgroup exceptions Exceptions
 * @ingroup constants
 */


/* Library Imports */
#import <Wordnik/WNConstants.h>
#import <Wordnik/WNClient.h>
#import <Wordnik/WNWord.h>

#import <Wordnik/WNWordDataSource.h>
#import <Wordnik/WNWordNetworkDataSource.h>

/**
 * @mainpage Wordnik Data SDK
 *
 * @section intro_sec Introduction
 *
 * The Wordnik data SDK provides a common API for accessing Wordnik's API and local data from iOS and Mac OS X
 * applications.
 *
 * @section doc_sections Documentation Sections
 * - @subpage programming_guide
 * - @subpage error_handling
 */

/**
 * @page programming_guide Wordnik Data SDK Programming Guide
 * @todo Document non-block delegate/observer methods to implement here.
 *
 * @section config Configuring the Wordnik Client
 *
 * @code
 * WNClientConfig *config = [WNClientConfig configWithAPIKey: @"MY_API_KEY"];
 * WNClient *client = [WNClient clientWithConfig: config];
 * @endcode
 *
 * @section auth Authentication
 *
 * @code
 * WNClientCredentials *creds = [WNClientCredentials credentialsWithUsername: @"user" password: @"password"];
 * [client loginWithCredentials: creds completionBlock: ^(NSError *error) {
 *     if (error != nil)
 *         NSLog(@"Authentication failed: %@", error);
 * }];
 * @endcode
 *
 * @section word_lookup Word Lookup
 *
 * @subsection single_word Single Word
 * @code
 *
 * // Create definition request for 'zebra', using the webster dictionary.
 * WNWordDefinitionRequest *definitionReq;
 *
 * NSSet *partsOfSpeech = [NSSet setWithObjects: [WNPartsOfSpeech noun], [WNPartOfSpeech verb], nil];
 * definitionReq = [WNWordDefinitionRequest requestWithDictionary: [WNDictionary websterDictionary]
 *                                                  partsOfSpeech: partsOfSpeech
 *                                                 maxResultCount: WNUnlimitedResultLength];
 *
 * WNWordRequest *req = [WNWordRequest requestWithWordString: @"zebra" 
 *                                      requestCanonicalForm: NO
 *                                           elementRequests: [NSArray arrayWithObject: definitionReq]];
 * 
 * // Issue the request
 * [client wordWithRequest: req completionBlock: ^(WNWord *word, NSError *error) {
 *     if (error != nil) {
 *          NSLog(@"Word lookup failed failed: %@", error);
 *          return;
 *     }
 *
 *     // Iterate over all noun definitions
 *     for (WNWordDefinition *definition in [word.definitionList definitionsForPartOfSpeech: [WNPartOfSpeech noun]]) {
 *          NSLog(@"Got definition: %@", definition.text);
 *     }
 * }];
 * @endcode
 *
 * @subsection multiple_words Multiple Words
 * @code
 *
 * // Create definition request
 * WNWordDefinitionRequest *definitionReq = [WNWordDefinitionRequest request];
 * NSArray *wordElementRequests = [NSArray arrayWithObject: ];
 *
 * // Create requests for 'zebra' and 'elephant'
 * WNWordRequest *zebra, *elephant;
 *
 * zebra = [WNWordRequest requestWithWordString: @"zebra" 
 *                         requestCanonicalForm: NO
 *                              elementRequests: wordElementRequests];
 * elephant = [WNWordRequest requestWithWordString: @"elephant" 
 *                            requestCanonicalForm: NO
 *                                 elementRequests: wordElementRequests];
 * 
 * // Issue the request
 * NSArray *wordRequests = [NSArray arrayWithObjects: zebra, elephant, nil];
 * [client wordsWithRequests: wordRequests completionBlock: ^(NSArray *words, NSError *error) {
 *     if (error != nil) {
 *          NSLog(@"Word lookup failed failed: %@", error);
 *          return;
 *     }
 *
 *     for (WNWord *word in words) {
 *         NSLog(@"Got word response for %@", word.wordString);
 *         for (WNWordDefinition *definition in word.definitionList.definitions)
 *             NSLog(@"Got definition: %@", definition.text);
 *         }
 *     }
 * }];
 * @endcode
 */

/**
 * @page error_handling Error Handling Programming Guide
 *
 * Where a method may return an error, Wordnik provides access to the underlying cause via an
 * optional NSError argument.
 *
 * All returned errors will be a member of one of the below defined domains, however, new domains and
 * error codes may be added at any time. If you do not wish to report on the error cause, many methods
 * support a simple form that requires no NSError argument.
 *
 * @section Error Domains, Codes, and User Info
 *
 * @subsection error_domains Errors
 *
 * Any errors in Wordnik use the #WNErrorDomain error domain, and and one
 * of the error codes defined in #WNErrorCode.
 */
