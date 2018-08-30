
// NanorepUI version number: v1.7.0.rc10 

//
//  SpeechReconitionDelegate.h
//  NanorepUI
//
//  Created by Nissim Pardo on 28/08/2018.
//

#import <Foundation/Foundation.h>
#import <NRAccessibility/NRSpeechRecognizerAuthorizationStatus.h>

@protocol SpeechReconitionDelegate <NSObject>
- (void)speechRecognitionStatus:(NRSpeechRecognizerAuthorizationStatus)status;
@end
