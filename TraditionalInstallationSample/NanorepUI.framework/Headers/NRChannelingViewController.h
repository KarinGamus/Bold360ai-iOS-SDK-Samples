
// NanorepUI version number: v1.6.1 

//
//  NRChannelingViewController.h
//  NanoRepWidget
//
//  Created by Nissim Pardo on 24/02/2016.
//  Copyright © 2016 nanorep. All rights reserved.
//

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
