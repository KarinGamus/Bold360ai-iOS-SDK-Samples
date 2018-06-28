
// NanorepUI version number: v1.6.0 

//
//  BrowserViewController.h
//  NanorepUI
//
//  Created by Nissim Pardo on 13/04/2018.
//  Copyright © 2018 nanorep. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BaseViewController.h"
@protocol BrowserViewControllerDelgate
- (void)didSelectLinkedArticle:(NSString *)articleId;
@end

@interface BrowserViewController : BaseViewController
@property (nonatomic, copy) NSURLRequest *request;
@property (nonatomic, weak) id<BrowserViewControllerDelgate> delegate;
@end
