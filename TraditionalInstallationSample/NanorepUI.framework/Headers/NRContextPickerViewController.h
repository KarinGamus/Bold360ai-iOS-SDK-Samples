
// NanorepUI version number: v1.6.1 

//
//  NRContextPickerViewController.h
//  NanorepUI
//
//  Created by Nissim Pardo on 14/04/2017.
//  Copyright © 2017 nanorep. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <NanorepEngine/NanorepEngine.h>

@class NRContextPickerViewController;
@protocol NRContextPickerViewControllerDelegate <NSObject>

- (void)controller:(NRContextPickerViewController *)controller didPickContext:(NSString *)context response:(NRSearchResponse *)searchResponse;

@end

@interface NRContextPickerViewController : UIViewController
@property (nonatomic) SearchAnswer *answer;
@property (nonatomic, copy) NSArray *contextNames;
@property (nonatomic, weak) id<NRContextPickerViewControllerDelegate> delegate;
@property (nonatomic, copy) NSString *query;
@end
