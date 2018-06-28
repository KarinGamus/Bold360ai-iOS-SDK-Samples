
// NanorepUI version number: v1.6.0 

// ===================================================================================================
// Copyright © 2018 nanorep.
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

#import <UIKit/UIKit.h>
#import "NRBotConfiguration.h"
#import <NanorepEngine/NanorepEngine.h>
#import "NRQuickOptionWrapper.h"
#import "NRCarouselQuickOption.h"
#import "NRApplicationContentHandler.h"
#import "HistoryProvider.h"

@class NRConversationalViewController;
@protocol NRCustomContentHandler <NSObject>
- (void)chatReady:(NRConversationalViewController *)controller;
- (void)controller:(NRConversationalViewController *)controller didSendStatement:(NSString *)statement;
- (void)controller:(NRConversationalViewController *)controller didStartCustomChatProvider:(NSString *)chatProviderId query:(NSString *)query;
- (void)controller:(NRConversationalViewController *)controller didFailWithError:(NSError *)error;
- (void)controller:(NRConversationalViewController *)controller didRequestShare:(NSString *)shareText;
- (void)controller:(NRConversationalViewController *)controller didRequestLocation:(void(^)(double latitude, double longitude))locationHandler;
- (BOOL)controller:(NRConversationalViewController *)controller shouldHandleFormPresentation:(UIViewController *)formController;
@end

@interface NRConversationalViewController : UIViewController
- (instancetype)initWithAccountParams:(AccountParams *)accountParams;
@property (nonatomic, readonly) NanoRep *nanorep;
@property (nonatomic, copy) NSNumber *conversationId;
@property (nonatomic, weak) id<NRChatEngineDelegate> delegate;
@property (nonatomic, weak) id<NRCustomContentHandler> customChatContentHandler;
@property (nonatomic, weak) id<NRApplicationContentHandler> applicationContentHandler;
@property (nonatomic, strong) NRBotConfiguration *configuration;
@property (weak, nonatomic, readonly) IBOutlet UIView *searchView;
@property (nonatomic, weak) id<HistoryProvider> historyProvider;

@property (nonatomic) BOOL enableCustomContent;
- (void)sendMessage:(NSString *)message;

- (void)messeage:(NSString *)message withId:(NSString *)articleId;

- (void)injectQuickOption:(NRQuickOptionWrapper *)optionWrapper;

- (void)linkedArticle:(NSString *)articleId title:(NSString *)title;
@end
