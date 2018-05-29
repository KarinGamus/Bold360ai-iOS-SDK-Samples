//
//  ChannelPickerDelegate.h
//  NanorepUI
//
//  Created by Nissim Pardo on 26/04/2018.
//  Copyright © 2018 nanorep. All rights reserved.
//

#import<Foundation/Foundation.h>
#import "NRResult.h"

@protocol ChannelPickerDelegate<NSObject>
- (void)didSelectChannel:(NRChanneling *)channel view:(UIView *)channelView forResult:(NRResult *)result;
@property (nonatomic) UIViewController *presentingViewController;
@end
