
// NanorepUI version number: v1.5.8.rc2 

//
//  NRErrorHandler.h
//  NanoRepSDK
//
//  Created by Nissim Pardo on 22/09/2016.
//  Copyright © 2016 nanorep. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, NRErrorSource) {
    NRErrorSourceNoConnection,
    NRErrorSourceTimeOut,
    NRErrorSourceServerError
};

@protocol NRErrorHandlerDelegate <NSObject>

- (void)didFailWithSource:(NRErrorSource)errorSource;
- (void)didRecover;

@end

@interface NRErrorHandler : NSObject
+ (NRErrorHandler *)shared;


@property (nonatomic, strong) NSError *error;
@property (nonatomic) BOOL errorState;

@property (nonatomic, weak) id<NRErrorHandlerDelegate> delegate;
@end
