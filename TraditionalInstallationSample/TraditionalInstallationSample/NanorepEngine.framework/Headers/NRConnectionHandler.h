
// NanorepUI version number: v1.5.8.rc2 

//
//  NRConnectinHandler.h
//  NanorepUI
//
//  Created by zahi on 12/21/17.
//  Copyright © 2017 nanorep. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol NRConnectionHandler<NSObject>
- (void)open:(nonnull NSURLRequest *)request completion:(nonnull void (^)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completion;
- (nullable NSData *)fetchDataAtRequest:(nonnull NSURLRequest *)request error:(NSError *_Nullable*_Nullable)error;
@end
