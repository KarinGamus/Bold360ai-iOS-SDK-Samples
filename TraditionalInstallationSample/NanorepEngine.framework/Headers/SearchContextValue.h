//
//  SearchContextValue.h
//  NanorepUI
//
//  Created by Nissim Pardo on 19/04/2017.
//  Copyright © 2017 nanorep. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NRBaseResponse.h"

@interface SearchContextValue : NRBaseResponse
@property (nonatomic, copy, readonly) NSString *name;
@property (nonatomic, readonly) NSInteger flags;
@property (nonatomic, copy, readonly) NSNumber *id;
@property (nonatomic, copy, readonly) NSString *selectionText;
@end
