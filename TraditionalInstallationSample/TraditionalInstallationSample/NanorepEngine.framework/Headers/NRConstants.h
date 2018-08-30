
// NanorepUI version number: v1.5.8.rc2 

//
//  NRConstants.h
//  NanoRepSDK
//
//  Created by Nissim Pardo on 8/25/15.
//  Copyright (c) 2015 nanorep. All rights reserved.
//
#import <Foundation/Foundation.h>
extern NSString *const NRSpeechToTextNuance;
extern NSString *const NRSpeechToTextOpenEars;

#define AppName [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleDisplayName"]
#define AppVersion [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]

