
// NanorepUI version number: v1.7.0.rc10 

// ===================================================================================================
// Copyright © 2018 bold360ai(LogMeIn).
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

#import <UIKit/UIKit.h>
#import "BaseViewController.h"
@protocol BrowserViewControllerDelgate
- (void)didSelectLinkedArticle:(NSString *)articleId;
@end

@interface BrowserViewController : BaseViewController
@property (nonatomic, copy) NSURLRequest *request;
@property (nonatomic, weak) id<BrowserViewControllerDelgate> delegate;
@end
