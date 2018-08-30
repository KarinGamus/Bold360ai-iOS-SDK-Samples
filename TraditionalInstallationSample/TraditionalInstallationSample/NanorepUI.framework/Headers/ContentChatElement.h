
// NanorepUI version number: v1.7.0.rc10 

// ===================================================================================================
// Copyright © 2018 bold360ai(LogMeIn).
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

#import <Foundation/Foundation.h>
#import "StorableChatElement.h"
#import <NanorepEngine/NSDictionary+Parsed.h>

/************************************************************/
// MARK: - ContentChatElement
/************************************************************/

extern NSString *const ChatElementDesignBotIncoming;
extern NSString *const ChatElementDesignBotOutgoing;
extern NSString *const ChatElementDesignSystem;
extern NSString *const ChatElementDesignCustomIncoming;
extern NSString *const ChatElementDesignCustomOutgoing;


/**
 A ContentChatElement is a wrapper used to define the type of chat (local, remote)
 */
@interface ContentChatElement : NSObject <StorableChatElement>
@property (nonatomic, copy) NSNumber *articleId;

// Enable set internally (replace readonly with readwrite)
@property (nonatomic, copy) NSString *design;

- (instancetype)initWithType:(ChatElementType)type content:(NSString*)content;

@end
