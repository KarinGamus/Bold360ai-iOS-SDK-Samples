
// NanorepUI version number: v1.6.0 

//
//  NRApplicationContentHandler.h
//  NanorepUI
//
//  Created by Nissim Pardo on 27/08/2017.
//  Copyright © 2017 nanorep. All rights reserved.
//

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
