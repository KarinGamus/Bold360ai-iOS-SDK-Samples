
// NanorepUI version number: v1.6.0 

//
//  NRCarouselQuickOption.h
//  NanorepUI
//
//  Created by Nissim Pardo on 09/08/2017.
//  Copyright © 2017 nanorep. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NRQuickOption.h"

typedef NS_ENUM(NSInteger, CarouselLayout) {
    CarouselLayoutDefault,
    CarouselLayoutDetailed
};

@interface NRCarouselQuickOption : NRQuickOption
@property (nonatomic) CarouselLayout layout;
@property (nonatomic, copy) NSString *bottomText;
@property (nonatomic, copy) NSString *optionDescription;
@property (nonatomic, copy) NSString *imagePath;
@end
