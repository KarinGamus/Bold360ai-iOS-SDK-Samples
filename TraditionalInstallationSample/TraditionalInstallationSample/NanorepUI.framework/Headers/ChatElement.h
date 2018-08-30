
// NanorepUI version number: v1.7.0.rc10 

// ===================================================================================================
// Copyright © 2018 bold360ai(LogMeIn).
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

typedef NS_ENUM(NSInteger, ChatElementSource) {
    ChatElementSourceDynamic,
    ChatElementSourceHistory
};

/************************************************************/
// MARK: - ChatElement
/************************************************************/

@protocol ChatElement <NSObject>

/************************************************************/
// MARK: - Properties
/************************************************************/

/**
 The DB id
 */
@property (nonatomic, copy, readonly) NSNumber *elementId;

/**
 The type of chat element
 */
@property (nonatomic, readonly) ChatElementType type;
/**
 The creation date of chat item.
 */
@property (nonatomic, copy) NSDate *timestamp;
/**
 The content of chat item (text, json..)
 */
@property (nonatomic, copy, readonly) NSString *text;

@property (nonatomic, assign) ChatElementSource source;

@end
