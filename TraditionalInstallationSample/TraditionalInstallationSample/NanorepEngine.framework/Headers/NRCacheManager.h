
// NanorepUI version number: v1.5.8.rc2 

//
//  NRCacheManager.h
//  NanoRepSDK
//
//  Created by Nissim Pardo on 8/28/15.
//  Copyright (c) 2015 nanorep. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NRCacheManager : NSObject
+ (void)storeAnswerById:(NSString *)answerId answer:(id)answer;
+ (id)answerById:(NSString *)answerId;
@end
