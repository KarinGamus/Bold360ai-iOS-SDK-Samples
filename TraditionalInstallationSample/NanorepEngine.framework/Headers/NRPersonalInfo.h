
// NanorepUI version number: v1.5.6.1 

//
//  NRPrivateInfo.h
//  ConversationEngine
//
//  Created by Nissim Pardo on 01/03/2017.
//  Copyright © 2017 nanorep. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NRAction : NSObject
@property (nullable, nonatomic, copy) NSString *actionId;
@property (nullable, nonatomic, copy) NSString *text;
@property (nullable, nonatomic, copy) NSDictionary *userInfo;
@end

@interface NRPersonalInfo : NSObject
@property (nullable, nonatomic, copy, readonly) NSString *personalInfoId;
@property (nullable, nonatomic, copy, readonly) NSArray<NSString *> *methodArgs;
@property (nullable, nonatomic, copy) void (^personalInfoCallback)(NSString * _Nullable replaceString, NRAction * _Nullable action);
@end
