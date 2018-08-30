
// NanorepUI version number: v1.7.0.rc10 

// ===================================================================================================
// Copyright © 2018 bold360ai(LogMeIn).
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

#import <Foundation/Foundation.h>

@protocol AccountProvider <NSObject>
- (void)provideAccountInfo:(NSString *)apiKey handler:(void (^)(NSDictionary *info))handler;
- (void)storeInfo:(NSDictionary *)info forKey:(NSString *)apiKey;
@end
