
// NanorepUI version number: v1.7.0.rc10 

// ===================================================================================================
// Copyright © 2018 bold360ai(LogMeIn).
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

#import <Foundation/Foundation.h>
#import "NRQuickOption.h"


@interface NRQuickOptionWrapper : NSObject
- (void)setKind:(NRQuickOptionKind)kind;
- (void)setType:(NRQuickOptionType)type;

@property(nonatomic, copy) NSString *text;
@property(nonatomic, readonly, copy) NSString *inJSON;
@property (nonatomic) BOOL cached;

- (void)addQuickOption:(NRQuickOption *)quickOption;
@end
