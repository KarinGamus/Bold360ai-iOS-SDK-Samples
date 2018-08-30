
// NanorepUI version number: v1.7.0.rc10 

// ===================================================================================================
// Copyright © 2018 bold360ai(LogMeIn).
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

#import <Foundation/Foundation.h>
#import "ChatElement.h"

@interface PreChatInfo : NSObject
@property (nonatomic, assign) BOOL loading;
@property (nonatomic, readwrite) id<ChatElement> welcomeMessage;
@property (nonatomic, copy) NSDictionary *extraInfo;
@end
