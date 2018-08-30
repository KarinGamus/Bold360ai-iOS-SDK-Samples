
// NanorepUI version number: v1.7.0.rc10 

// ===================================================================================================
// Copyright © 2018 bold360ai(LogMeIn).
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

#import <Foundation/Foundation.h>
#import <NanorepEngine/NanorepEngine.h>
#import "NRChatControllerDelegate.h"
#import "NREntitiesProvider.h"
#import "NRBotConfiguration.h"
#import "HistoryProvider.h"
#import "AccountProvider.h"
#import "ChatHandler.h"
#import "SpeechReconitionDelegate.h"

@interface NRChatController : NSObject
@property (nonatomic, copy) void (^initialize)(UIViewController *chatController, NRConfiguration *configuration, NSError *error);
@property (nonatomic, weak) id<NRChatControllerDelegate> delegate;
@property (nonatomic, weak) id<NREntitiesProvider> entitiesProvider;
@property (nonatomic, weak) id<HistoryProvider> historyProvider;
@property (nonatomic, weak) id<AccountProvider> accountProvider;
@property (nonatomic, strong) NRBotConfiguration *uiConfiguration;
@property (nonatomic, weak) id<ChatHandler> handOver;
@property (nonatomic, weak) id<SpeechReconitionDelegate> speechReconitionDelegate;

- (instancetype)initWithAccount:(Account *)account;
- (void)repostStatements:(NSArray<StorableChatElement> *)elements;
@end
