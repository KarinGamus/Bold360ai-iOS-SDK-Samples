
// NanorepUI version number: v1.6.0 

// ===================================================================================================
// Copyright © 2018 nanorep.
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

#import <Foundation/Foundation.h>

/************************************************************/
// MARK: - NRResources
/************************************************************/

@interface NRResources : NSObject
@property (nonatomic, copy) NSString *rootPath;
@property (nonatomic, copy) NSArray<NSString *> *webResources;
@end

/************************************************************/
// MARK: - NRBotConfiguration
/************************************************************/

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
