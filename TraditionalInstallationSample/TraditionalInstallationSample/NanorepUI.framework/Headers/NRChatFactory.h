
// NanorepUI version number: v1.7.0.rc10 

// ===================================================================================================
// Copyright © 2018 bold360ai(LogMeIn).
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

#import <Foundation/Foundation.h>
#import <NanorepEngine/NanorepEngine.h>
#import "ChatHandler.h"

@interface NRChatFactory : NSObject
+ (id<ChatHandler>)createChatHandlerForAccount:(Account *)account;
@end
