
// NanorepUI version number: v1.7.0.rc10 

// ===================================================================================================
// Copyright © 2018 bold360ai(LogMeIn).
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

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
