
// NanorepUI version number: v1.6.0 

//
//  ExtraData.h
//  NanorepUI
//
//  Created by Nissim Pardo on 13/02/2018.
//  Copyright © 2018 nanorep. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Value : NSObject
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) id value;
@end

@interface ExtraData : NSObject
@property (nonatomic, copy) NSString *postUrl;
@property (nonatomic, copy) NSArray<Value *> *values;
@property (nonatomic, copy) NSDictionary<NSString *, NSObject *> *fileInfos;
@end
