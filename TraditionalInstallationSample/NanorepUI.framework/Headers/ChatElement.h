
// NanorepUI version number: v1.6.1 

// ===================================================================================================
// Copyright © 2018 nanorep.
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

/************************************************************/
// MARK: - ChatElementType
/************************************************************/

/**
 An AgentType is an enum of different agent states
 */
typedef NS_ENUM(NSInteger, ChatElementType) {
    /// Chat element type is datestamp
    DatestampElement,
    /// Chat element type is local
    LocalElement,
    /// Chat element type is remote
    RemoteElement,
    /// Chat element type is carousel
    CarouselElement
};

/************************************************************/
// MARK: - ChatElement
/************************************************************/

@protocol ChatElement <NSObject>

/************************************************************/
// MARK: - Properties
/************************************************************/

/**
 The type of chat element
 */
@property (nonatomic, readonly) ChatElementType type;
/**
 The creation date of chat item.
 */
@property (nonatomic, readonly) NSTimeInterval timestamp;
/**
 The content of chat item (text, json..)
 */
@property (nonatomic, copy, readonly) NSString *content;

@end
