
// NanorepUI version number: v1.7.0.rc10 

// ===================================================================================================
// Copyright © 2018 bold360ai(LogMeIn).
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

#import <Foundation/Foundation.h>

@protocol NRSearchBarDelegate <NSObject>
- (void)fetchSuggestions:(NSString *)text;
- (void)search:(NSString *)text;
- (void)clear;
- (void)removeSuggestions;
@end
