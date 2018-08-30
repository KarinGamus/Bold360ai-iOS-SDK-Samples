
// NanorepUI version number: v1.7.0.rc10 

// ===================================================================================================
// Copyright © 2018 bold360ai(LogMeIn).
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

#import <Foundation/Foundation.h>
#import <NanorepEngine/NanorepEngine.h>
#import "StorableChatElement.h"
#import "ChatEventHandler.h"
#import "NRChatControllerDelegate.h"
#import "PreChatInfo.h"

typedef NS_ENUM(NSInteger, ChatEvent) {
    ChatEventReadmore,
    ChatEventChannel
};


@protocol ChatHandlerDelegate <NSObject>
- (void)presentStatement:(id<StorableChatElement>)statement;
- (void)updateStatus:(StatementStatus)status element:(id<StorableChatElement>)element;
- (void)event:(ChatEvent)event withParams:(NSDictionary *)params;
- (void)preChat:(PreChatInfo *)preChatInfo;
- (void)postChat:(NSDictionary *)postChatInfo;
@end

@protocol ChatHandler;
@protocol ChatHandlerProvider <NSObject>
- (void)shouldReplaceChatHandelr:(NSDictionary *)chatHandlerParams;
- (void)didEndChat:(id<ChatHandler>)chatHandler;
@end

@protocol ChatHandler <ChatEventHandler>
- (void)startChat:(NSDictionary *)chatInfo;
- (void)endChat;
- (void)postStatement:(id<StorableChatElement>)statement;
@property (nonatomic, weak) id<ChatHandlerDelegate> delegate;
@property (nonatomic, weak) id<NRChatControllerDelegate> chatControllerDelegate;
@property (nonatomic, weak) id<ChatHandlerProvider> chatHandlerProvider;
@end


