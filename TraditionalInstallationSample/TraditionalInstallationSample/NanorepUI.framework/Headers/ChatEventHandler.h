
// NanorepUI version number: v1.7.0.rc10 

// ===================================================================================================
// Copyright © 2018 bold360ai(LogMeIn).
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

#import <Foundation/Foundation.h>

@protocol ChatEventHandler <NSObject>
- (void)handleClickedLink:(NSURL *)link;
- (void)handleEvent:(NSDictionary *)eventParams;
@end
