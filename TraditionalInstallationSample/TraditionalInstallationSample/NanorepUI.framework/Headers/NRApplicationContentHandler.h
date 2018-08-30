
// NanorepUI version number: v1.7.0.rc10 

// ===================================================================================================
// Copyright © 2018 bold360ai(LogMeIn).
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

#import <Foundation/Foundation.h>
#import "NRQuickOption.h"

@class NRConversationalViewController;
@protocol NRApplicationContentHandler <NSObject>
- (BOOL)presentingController:(UIViewController *)controller shouldHandleClickedLink:(NSString *)link;
- (void)didClickToCall:(NSString *)phoneNumber;
- (void)didClickLink:(NSString *)url;
- (void)didSessionExpire;
- (void)controller:(NRConversationalViewController *)controller didClickApplicationQuickOption:(NRQuickOption *)quickOption;
@end
