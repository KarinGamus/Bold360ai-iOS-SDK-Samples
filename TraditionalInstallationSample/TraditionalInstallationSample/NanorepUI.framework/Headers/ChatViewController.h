
// NanorepUI version number: v1.7.0.rc10 

// ===================================================================================================
// Copyright © 2018 bold360ai(LogMeIn).
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

#import <UIKit/UIKit.h>
#import "ChatHandler.h"
#import "NRBotConfiguration.h"
#import "HistoryProvider.h"
#import "LocalChatElement.h"
#import "SpeechReconitionDelegate.h"

/************************************************************/
// MARK: - ChatViewController
/************************************************************/

@interface ChatViewController : UIViewController<ChatHandlerDelegate>

/**
 `ChatHandler` used as Bot/ Handover handler
 */
@property (nonatomic, strong) id<ChatHandler> chatHandler;

/**
 `ChatEventHandler` object used to handle events on chat.
 */
@property (nonatomic, strong) id<ChatEventHandler> chatEventHandler;

/**
 `NRBotConfiguration` object used to configure bot.
 */
@property (nonatomic, strong) NRBotConfiguration *configuration;

/**
 `HistoryProvider` object used to manage history.
 */
@property (nonatomic, weak) id<HistoryProvider> historyProvider;

/**
 `SpeechReconitionDelegate` object used to manage speech recognition status.
 */
@property (nonatomic, weak) id<SpeechReconitionDelegate> speechReconitionDelegate;
@end
