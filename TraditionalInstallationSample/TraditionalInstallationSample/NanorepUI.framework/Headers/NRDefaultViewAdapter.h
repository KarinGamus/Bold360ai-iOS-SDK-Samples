
// NanorepUI version number: v1.7.0.rc10 

// ===================================================================================================
// Copyright © 2018 bold360ai(LogMeIn).
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

#import <Foundation/Foundation.h>
#import "NRAbstractViews.h"

@interface NRDefaultViewAdapter : NSObject <NanorepViewAdapter>
@property (nonatomic, weak) id<NanorepViewAdapter> appAdapter;
@end
