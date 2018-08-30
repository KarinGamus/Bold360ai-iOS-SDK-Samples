
// NanorepUI version number: v1.5.8.rc2 

//
//  NSDictionary+Parsed.h
//  NanoRepSDK
//
//  Created by Nissim Pardo on 8/18/15.
//  Copyright (c) 2015 nanorep. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NRChanneling.h"
#import "NRQueryResult.h"


@interface NSDictionary (Parsed)
@property (nonatomic, readonly, copy) NSString *wrapped;
@property (nonatomic, readonly, copy) NSString *asQuery;
@property (nonatomic, readonly, copy) NSString *inJSON;

- (NSArray<NSAttributedString *> *)parseAutoComplete:(UIFont *)font;
@end
