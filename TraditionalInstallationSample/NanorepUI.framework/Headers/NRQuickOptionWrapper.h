
// NanorepUI version number: v1.6.1 

//
// Created by Nissim Pardo on 07/06/2017.
// Copyright (c) 2017 nanorep. All rights reserved.
//

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
