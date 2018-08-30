
// NanorepUI version number: v1.7.0.rc10 

// ===================================================================================================
// Copyright © 2018 bold360ai(LogMeIn).
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

#import <UIKit/UIKit.h>
#import "ExtraData.h"

@protocol NRChannelingViewControllerDelegate <NSObject>

- (void)didCancel:(NSString *)channelLink;
- (void)didFailWithError:(NSError *)error;
- (void)didSend:(NSString *)channelLink;
- (void)didFetchFormData:(ExtraData *)formData;

@end

@interface NRChannelingViewController : UIViewController 
@property (nonatomic, copy) NSURL *channelURL;
@property (nonatomic, weak) id<NRChannelingViewControllerDelegate> delegate;
@property (nonatomic, copy) NSString *channelTitle;
@end
