//
//  NanorepPersonalInfoHandler.h
//  NanorepUI
//
//  Created by Nissim Pardo on 12/04/2018.
//  Copyright © 2018 nanorep. All rights reserved.
//

@protocol NanorepPersonalInfoHandler <NSObject>

- (void)personalInfoWithExtraData:(NSDictionary *)extraData channel:(NRChanneling *)channel completionHandler:(void(^)(NSDictionary *formData))handler;
- (void)didFetchExtraData:(NSDictionary *)formData;
- (void)didSubmitForm;
- (void)didCancelForm;
- (void)didFailSubmitFormWithError:(NSError *)error;
- (BOOL)shouldOverridePhoneChannel:(NRChannelingPhoneNumber *)phoneChannel;
- (void)didSubmitFeedback:(NSDictionary *)info;
@end
