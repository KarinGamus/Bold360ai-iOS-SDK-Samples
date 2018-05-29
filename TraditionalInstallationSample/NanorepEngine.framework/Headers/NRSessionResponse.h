//
//  NRSession.h
//  NanorepUI
//
//  Created by Nissim Pardo on 12/04/2017.
//  Copyright © 2017 nanorep. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NRBaseResponse.h"

@interface NRSessionResponse : NRBaseResponse
@property (nonatomic, copy, readonly) NSString *sessionId;
@property (nonatomic, copy) NSNumber *timeout;
@property (nonatomic, copy, readonly) NSNumber *status;
@end
