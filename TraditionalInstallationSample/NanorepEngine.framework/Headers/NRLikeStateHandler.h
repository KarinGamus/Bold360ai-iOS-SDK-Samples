//
//  NRLikeState.h
//  NanorepUI
//
//  Created by Nissim Pardo on 02/07/2017.
//  Copyright © 2017 nanorep. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NRLikeStateHandler : NSObject
- (void)updateLikeState:(BOOL)likeState ForId:(NSString *)articleId;
- (NSNumber *)likeStateWithId:(NSString *)articleId;
@end
