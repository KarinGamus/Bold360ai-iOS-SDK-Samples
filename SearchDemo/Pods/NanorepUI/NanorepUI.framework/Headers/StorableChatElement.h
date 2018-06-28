
// NanorepUI version number: v1.6.0 

// ===================================================================================================
// Copyright © 2018 nanorep.
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

#import "AgentType.h"
#import "ChatElement.h"
#import "StatementStatus.h"

/************************************************************/
// MARK: - StorableChatElement
/************************************************************/

@protocol StorableChatElement <ChatElement>

/************************************************************/
// MARK: - Properties
/************************************************************/

/**
 The chat elements converted to bytes
 */
@property (nonatomic, copy, readonly) NSString *storageKey;
/**
 The current agent type.
 */
@property (nonatomic, readonly) AgentType agentType;
/**
 The current statement status.
 */
@property (nonatomic, readonly) StatementStatus status;

@end
