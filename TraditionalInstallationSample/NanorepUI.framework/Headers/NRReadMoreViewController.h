
// NanorepUI version number: v1.6.1 

//
//  NRReadMoreViewController.h
//  NanorepUI
//
//  Created by Nissim Pardo on 09/05/2017.
//  Copyright © 2017 nanorep. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NRResultPresntationView.h"
#import "NRApplicationContentHandler.h"
#import "NanorepPersonalInfoHandler.h"
#import "BaseViewController.h"

@class NRReadMoreViewController;
@protocol NRReadMoreViewControllerDelegate<NSObject>
- (void)readmoreController:(NRReadMoreViewController *)readmoreController presentModally:(UIViewController *)controller;
@optional
- (void)readmoreController:(NRReadMoreViewController *)readmoreController updateChannels:(NRResult *)result;
@end


@interface NRReadMoreViewController : BaseViewController
@property (nonatomic, copy) NSString *articleId;
@property (nonatomic, weak) id<NRApplicationContentHandler> applicationHandler;
@property (nonatomic, copy) NSString *text;
@property (nonatomic, copy) NSString *articleTitle;
@property (nonatomic) NRResult *result;
@property (nonatomic, weak) id<NanorepPersonalInfoHandler> infoHandler;
@property (nonatomic, weak) id<NRReadMoreViewControllerDelegate> delegate;
@property (nonatomic, weak) IBOutlet NRResultPresntationView *resultView;
@property (nonatomic, strong) id<ChannelPickerDelegate> channelPickerDelegate;

- (void)dismiss;
@end
