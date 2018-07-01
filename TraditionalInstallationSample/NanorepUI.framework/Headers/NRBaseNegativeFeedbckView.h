
// NanorepUI version number: v1.6.1 

//
//  NRBaseNegativeFeedbckView.h
//  NanorepUI
//
//  Created by Nissim Pardo on 29/03/2018.
//  Copyright © 2018 nanorep. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NRAbstractViews.h"
#import "NSBundle+UIBundle.h"

@interface NRBaseNegativeFeedbckView : UIView <NRNegativeFeedback>
@property (nonatomic, weak) IBOutlet UIView *textHolder;
@property (weak, nonatomic) IBOutlet UILabel *title;
@property (weak, nonatomic) IBOutlet UIButton *closeButton;
@property (weak, nonatomic) IBOutlet UIButton *submitButton;

- (IBAction)close:(UIButton *)sender;
- (IBAction)submit:(UIButton *)sender;

- (void)addTextView:(UIView *)view;
@end
