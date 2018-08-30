
// NanorepUI version number: v1.5.8.rc2 

//
//  NRChanneling.h
//  NanoRepSDK
//
//  Created by Nissim Pardo on 28/12/2015.
//  Copyright © 2015 nanorep. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, NRChannelingType) {
    NRChannelingTypeCustomScript,
    NRChannelingTypeContactForm,
    NRChannelingTypeOpenCustomURL,
    NRChannelingTypeChatForm,
    NRChannelingTypePhoneNumber = 5
};


@interface NRChanneling : NSObject
- (instancetype)initWithParams:(NSDictionary *)params;
@property (nonatomic, copy, readonly) NSString *buttonText;
@property (nonatomic, copy, readonly) NSString *channelDescription;
@property (nonatomic, readonly) NRChannelingType type;
@end

@interface NRChannelingPhoneNumber : NRChanneling
@property (nonatomic, copy, readonly) NSString *phoneNumber;
@property (nonatomic, copy, readonly) NSString *customContent;
@end

@interface NRChannelingOpenCustomURL : NRChanneling
@property (nonatomic, copy, readonly) NSString *linkUrl;
@property (nonatomic, copy, readonly) NSString *linkTarget;
@property (nonatomic, copy, readonly) NSString *popupSize;
@end

@interface NRChannelingCustomScript : NRChanneling
@property (nonatomic, copy, readonly) NSString *scriptContent;
@end

@interface NRChannelingContactForm : NRChanneling
@property (nonatomic, copy, readonly) NSString *contactForms;
@property (nonatomic, copy, readonly) NSString *ticketingInterface;
@property (nonatomic, copy, readonly) NSString *showInArticle;
@property (nonatomic, copy, readonly) NSString *thankYouMessage;
@end

@interface NRChannelingChatForm : NRChanneling
@property (nonatomic, copy, readonly) NSString *chatProvider;
@property (nonatomic, copy, readonly) NSString *accountNum;
@property (nonatomic, copy, readonly) NSString *initialiseStatus;
@property (nonatomic, copy, readonly) NSString *agentSkill;
@property (nonatomic, copy, readonly) NSString *waitTime;
@property (nonatomic, copy, readonly) NSString *preChat;
@property (nonatomic, copy, readonly) NSString *postChat;
@property (nonatomic, readonly) BOOL hideSendToEmail;
@property (nonatomic, readonly) BOOL isPopup;
@property (nonatomic, copy, readonly) NSString *popupSize;
@property (nonatomic, copy, readonly) NSString *otherChatProviderValues;
@property (nonatomic, copy, readonly) NSString *accontNum;
@end
