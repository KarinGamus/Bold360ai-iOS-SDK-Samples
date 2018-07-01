
// NanorepUI version number: v1.5.6.1 

//
//  SearchAnswer.h
//  NanoRepSDK
//
//  Created by Nissim Pardo on 28/09/2016.
//  Copyright © 2016 nanorep. All rights reserved.
//

#import "NRQueryResult.h"
#import "SearchContextValue.h"


@protocol ContextValueHandler <NSObject>

- (SearchContextValue *)contextForId:(NSNumber *)contextId;
@property (nonatomic, readonly) NSString *multipleContext;

@end

@interface SearchAnswer : NRQueryResult
@property (nonatomic, readonly, copy) NSArray<NSNumber *> *contextSelection;
@property (nonatomic, readonly, copy) SearchContextValue *searchContext;
@property (nonatomic, readonly, copy) NSString *contextValue;
@property (nonatomic, strong) id<ContextValueHandler> contextValueHandler;
@end
