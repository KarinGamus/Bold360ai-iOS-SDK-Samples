
// NanorepUI version number: v1.6.1 

//
//  NRResultPresntationView.h
//  NanoRepWidget
//
//  Created by Nissim Pardo on 31/10/2016.
//  Copyright © 2016 nanorep. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ChannelPickerDelegate.h"


@class NRResultPresntationView;
@protocol NRResultPresntationViewControllerDelegate <NSObject>

- (void)didDismissResult;
- (void)didDislikeResult:(NRResultPresntationView *)resultView;
- (void)sendFeedback:(int)feedbackType
          resultView:(NRResultPresntationView *)resultView
           completion:(void(^)(NSString *resultId, int type, BOOL success))completion;
- (void)updateChannelsAtResultview:(NRResultPresntationView *)resultView;
- (void)resultView:(NRResultPresntationView *)resultView didSelectLinkedArticle:(NSString *)articleId;
- (void)resultView:(NRResultPresntationView *)resultView didClickLink:(NSURLRequest *)request;
@end

@interface NRResultPresntationView : UIView
@property (nonatomic) CGFloat startY;
@property (nonatomic, strong) NRResult *result;
@property (nonatomic, copy) NSArray<NRChanneling *> *channels;
@property (nonatomic, weak) id<NRResultPresntationViewControllerDelegate> delegate;
@property (nonatomic, weak) id<ChannelPickerDelegate> channelPickerDelegate;
@property (nonatomic, copy) NSString *body;
@property (nonatomic) BOOL withAnimation;
@property (nonatomic, copy) NSNumber *likeState;

- (void)cancelDislike;
@end
