
// NanorepUI version number: v1.5.5.1 

//
//  NRSpeechDelegate.h
//  NRAccessibility
//
//  Created by Nissim Pardo on 04/03/2018.
//  Copyright © 2018 Nissim Pardo. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, NRSpeechRecognizerAuthorizationStatus) {
    NRSpeechRecognizerAuthorizationStatusNotDetermined,
    NRSpeechRecognizerAuthorizationStatusDenied,
    NRSpeechRecognizerAuthorizationStatusRestricted,
    NRSpeechRecognizerAuthorizationStatusAuthorized
};

@protocol NRSpeechDelegate <NSObject>
- (void)recoredDidEnd;
- (void)speechDetected:(NSString *)text;
@end
