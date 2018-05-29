//
//  NRConfigurtion.h
//  ConversationUI
//
//  Created by Nissim Pardo on 19/03/2017.
//  Copyright © 2017 nanorep. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NRResources : NSObject
@property (nonatomic, copy) NSString *rootPath;
@property (nonatomic, copy) NSArray<NSString *> *webResources;
@end

@interface NRBotConfiguration : NSObject
- (NSURL *)chatContentURLWithHandler:(void(^)(NSURL *contentURL))completion;
@property (nonatomic, copy) NSURL *chatContentURL;
@property (nonatomic, copy) NSString *conversationId;
@property (nonatomic, copy) NSArray<NSString *> *entities;
@property (nonatomic) BOOL isRTL;
@property (nonatomic) NSInteger historyChatCount;
@property (nonatomic) BOOL withNavBar;
@property (nonatomic) NSString *logoName;
@property (nonatomic) NRResources *resources;
@end
