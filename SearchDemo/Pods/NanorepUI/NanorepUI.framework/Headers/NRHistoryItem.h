
// NanorepUI version number: v1.6.0 

//
//  NRHistoryItem.h
//  NanorepUI
//
//  Created by Nissim Pardo on 25/07/2017.
//  Copyright © 2017 nanorep. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <NanorepEngine/NanorepEngine.h>

@protocol HistoryItem
@property (nonatomic) BOOL isServer;
@property (nonatomic, copy, readonly) NSString *text;
@property (nonatomic, copy, readonly) NSString *articleId;
@property (nonatomic, readonly) BOOL isReadMore;
@end

@interface NRHistoryItem : NSObject <HistoryItem>
- (instancetype)initWithText:(NSString *)text;
- (instancetype)initWithResponse:(NRConversationalResponse *)response;
- (instancetype)initWithParams:(NSMutableDictionary *)params;



@property (nonatomic, copy) NSMutableDictionary *jsonParams;

@property (nonatomic, readonly, copy) NSString *inJSON;
@end
