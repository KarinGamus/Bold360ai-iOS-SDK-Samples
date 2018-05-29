//
//  NRBaseResponse.h
//  NanorepUI
//
//  Created by Nissim Pardo on 12/04/2017.
//  Copyright © 2017 nanorep. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NRBaseResponse : NSObject
- (instancetype)initWithParams:(NSDictionary *)params;
- (void)inflate:(NSDictionary *)params;
@end
