
// NanorepUI version number: v1.6.0 

//
//  NRChatView.h
//  NanorepUI
//
//  Created by Nissim Pardo on 14/05/2017.
//  Copyright © 2017 nanorep. All rights reserved.
//

#import <WebKit/WebKit.h>

@protocol NRChatViewDelegate <NSObject>
- (void)onReady;
- (void)addText:(NSString *)text isClient:(BOOL)isClient;
- (void)channel:(NSDictionary *)params;
- (void)readMore:(NSDictionary *)params;
- (void)linkedArticle:(NSString *)articleId title:(NSString *)title;
- (void)inlineChoice:(NSDictionary *)params;
- (void)location:(NSDictionary<NSString *, NSString *> *)params;
- (void)openInAppBrowser:(NSURLRequest *)request;
- (void)inAppNavigation:(NSString *)pageId;
- (void)share:(NSDictionary *)params;
- (void)customQuickOption:(NSDictionary *)params;
- (void)fetchPreviousHistory;
- (void)didFailWithError:(NSError *)error;
@end

@interface NRChatView : UIView
@property (nonatomic ,copy) NSDictionary *cachedConversation;
@property (nonatomic, weak) id<NRChatViewDelegate> chatViewDelegate;
@property (nonatomic, readonly) BOOL isLoaded;
@property (nonatomic) BOOL isRTL;
@property (nonatomic, readonly) UIScrollView *scrollView;

- (void)loadRequest:(NSURLRequest *)request;
- (void)reload;

- (void)injectMessage:(NSString *)jsString isClient:(BOOL)isClient;
@end
