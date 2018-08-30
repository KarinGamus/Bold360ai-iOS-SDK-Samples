
// NanorepUI version number: v1.7.0.rc10 

// ===================================================================================================
// Copyright © 2018 bold360ai(LogMeIn).
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

#import <UIKit/UIKit.h>
#import <NanorepEngine/NanorepEngine.h>
#import "NRQuickOption.h"
#import "StorableChatElement.h"

@protocol NRChatControllerDelegate <NSObject>
@optional
- (BOOL)shouldHandleFormPresentation:(UIViewController *)formController;
- (void)statement:(id<StorableChatElement>)statement didFailWithError:(NSError *)error;
- (BOOL)presentingController:(UIViewController *)controller shouldHandleClickedLink:(NSString *)link;
- (void)didClickToCall:(NSString *)phoneNumber;
- (void)didClickLink:(NSString *)url;
- (void)didClickApplicationQuickOption:(NRQuickOption *)quickOption;
@end
