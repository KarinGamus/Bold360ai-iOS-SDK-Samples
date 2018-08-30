
// NanorepUI version number: v1.5.8.rc2 

//
//  NRConversationAnswer.h
//  NanorepUI
//
//  Created by Nissim Pardo on 05/12/2016.
//  Copyright © 2016 nanorep. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NREntity.h"

typedef NS_ENUM (NSInteger, NROptionType) {
    NROptionTypePostback,
    NROptionTypeLocation,
    NROptionTypeURL
};

typedef NS_ENUM (NSInteger, NROptionKind) {
    NROptionKindUNKNOWN,
    NROptionKindOther,
    NROptionKindAskAnAgent,
    NROptionKindSupportCenterLink,
    NROptionKindChannel,
    NROptionKindClickToCall,
    NROptionKindReadMore,
    NROptionKindFeedback,
    NROptionKindLocation,
    NROptionKindInlineChoice,
    NROptionKindUrl,
    NROptionKindExternal
    
};

@interface NRConversationQuickOption : NSObject
- (instancetype _Nullable)initWithParams:(NSDictionary *_Nullable)params;
@property (nonatomic, copy) NSString * _Nullable text;
@property (nonatomic, copy, readonly) NSString * _Nullable postback;
@property (nonatomic) NROptionType type;
@property (nonatomic) NROptionKind kind;

@end

@interface NRConversationPersistentOption : NRConversationQuickOption
@property (nonatomic, copy, readonly) NSURL * _Nullable url;
@end

@interface NRConversationMissingEntity : NSObject
- (instancetype _Nullable )initWithStatement:(NSString *_Nullable)statement;

- (void)addEntity:(NREntity *_Nullable)entity;

@property (nonatomic, copy, readonly) NSString * _Nullable inJSON;
@end
