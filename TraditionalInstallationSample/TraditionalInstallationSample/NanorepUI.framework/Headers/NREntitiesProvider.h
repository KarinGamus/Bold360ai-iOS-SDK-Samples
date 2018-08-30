
// NanorepUI version number: v1.7.0.rc10 

// ===================================================================================================
// Copyright © 2018 bold360ai(LogMeIn).
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

#import <Foundation/Foundation.h>
#import <NanorepEngine/NanorepEngine.h>

@protocol NREntitiesProvider <NSObject>
- (void)shouldHandleMissingEntities:(NRConversationalResponse *)response
             missingEntitiesHandler:(void(^)(NRConversationMissingEntity *missingEntity))handler;

- (void)shouldHandlePersonalInformation:(NRPersonalInfo *)personalInfo;
@end
