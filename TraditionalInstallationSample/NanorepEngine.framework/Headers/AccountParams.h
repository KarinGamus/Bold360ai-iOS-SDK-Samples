
// NanorepUI version number: v1.5.6.1 

//
//  AccountParams.h
//  NanoRepSDK
//
//  Created by Nissim Pardo on 21/09/2016.
//  Copyright © 2016 nanorep. All rights reserved.
//

#import <Foundation/Foundation.h>
@interface DynamicContext: NSObject
- (instancetype)initWithContext:(NSString *)context;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *context;
@end

@interface AccountParams : NSObject
@property (nonatomic, copy) NSString *account;
@property (nonatomic, copy) NSString *knowledgeBase;
@property (nonatomic, copy) NSDictionary<NSString *, NSString *> *nanorepContext;
@property (nonatomic, copy) NSString *referrer;
@property (nonatomic, readonly, copy) NSString *accountId;
@property (nonatomic, copy) NSString *apiKey;
@property (nonatomic, copy) NSString *labelId;
@property (nonatomic, copy, readonly) NSString *dynamicContextDescription;
@property (nonatomic) BOOL allContextsMandatory;

- (void)appendDynamicContext:(DynamicContext *)context;

- (NSDictionary<NSString *,NSString *> *)resetDynamicContext;
@end
