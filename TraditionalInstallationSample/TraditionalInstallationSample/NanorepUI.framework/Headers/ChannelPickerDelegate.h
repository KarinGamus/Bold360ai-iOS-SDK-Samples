
// NanorepUI version number: v1.7.0.rc10 

// ===================================================================================================
// Copyright © 2018 bold360ai(LogMeIn).
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

#import<Foundation/Foundation.h>
#import "NRResult.h"

@protocol ChannelPickerDelegate<NSObject>
- (void)didSelectChannel:(NRChanneling *)channel view:(UIView *)channelView forResult:(NRResult *)result;
@property (nonatomic) UIViewController *presentingViewController;
@end
