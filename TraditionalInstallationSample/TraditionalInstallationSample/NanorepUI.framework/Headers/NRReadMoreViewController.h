
// NanorepUI version number: v1.7.0.rc10 

// ===================================================================================================
// Copyright © 2018 bold360ai(LogMeIn).
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

#import <UIKit/UIKit.h>
#import "NRResultPresntationView.h"
#import "NRChatControllerDelegate.h"
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
@property (nonatomic, weak) id<NRChatControllerDelegate> applicationHandler;
@property (nonatomic, copy) NSString *text;
@property (nonatomic, copy) NSString *articleTitle;
@property (nonatomic) NRResult *result;
@property (nonatomic, weak) id<NanorepPersonalInfoHandler> infoHandler;
@property (nonatomic, weak) id<NRReadMoreViewControllerDelegate> delegate;
@property (nonatomic, weak) IBOutlet NRResultPresntationView *resultView;
@property (nonatomic, strong) id<ChannelPickerDelegate> channelPickerDelegate;

- (void)dismiss;
@end
