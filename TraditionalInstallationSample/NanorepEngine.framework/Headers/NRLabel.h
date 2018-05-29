//
//  NRLabel.h
//  NanorepUI
//
//  Created by Nissim Pardo on 24/04/2017.
//  Copyright © 2017 nanorep. All rights reserved.
//

#import "NRFAQGroup.h"

@interface NRLabel : NRFAQGroup <NSCopying>
@property (nonatomic, copy) NSString *labelId;
@property (nonatomic, copy, readonly) NSString *context;
@property (nonatomic, copy, readonly) NSString *labelName;
@property (nonatomic, copy, readonly) NSURL *iconUrl;
@property (nonatomic) NSData *iconData;
@end
