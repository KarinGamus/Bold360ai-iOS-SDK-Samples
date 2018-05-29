//
//  NRFeedbackViewMulti.h
//  NanorepUI
//
//  Created by Nissim Pardo on 29/03/2018.
//  Copyright © 2018 nanorep. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NRBaseNegativeFeedbckView.h"
#import "MultipleChoiceView.h"

@interface NRFeedbackViewMulti : NRBaseNegativeFeedbckView
@property (strong, nonatomic) MultipleChoiceView *multipleChoiceView;
@end
