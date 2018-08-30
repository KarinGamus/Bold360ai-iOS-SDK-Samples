
// NanorepUI version number: v1.7.0.rc10 

// ===================================================================================================
// Copyright © 2018 bold360ai(LogMeIn).
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

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
