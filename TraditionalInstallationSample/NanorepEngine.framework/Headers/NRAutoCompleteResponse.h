
// NanorepUI version number: v1.5.6.1 

//
//  NRAutoCompleteResponse.h
//  NanorepUI
//
//  Created by Nissim Pardo on 12/04/2017.
//  Copyright © 2017 nanorep. All rights reserved.
//

#import "NRBaseResponse.h"
#import <UIKit/UIKit.h>

@interface NRAutoCompleteResponse : NRBaseResponse
@property (nonatomic, readonly, copy) NSArray<NSAttributedString *> *suggestions;
@property (nonatomic, copy) UIFont *font;
@property (nonatomic, copy) NSString *query;
@end
