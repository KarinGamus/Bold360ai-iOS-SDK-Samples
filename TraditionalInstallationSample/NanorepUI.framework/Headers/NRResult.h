//
//  NRResult.h
//  NanoRepWidget
//
//  Created by Nissim Pardo on 10/10/2016.
//  Copyright © 2016 nanorep. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <NanorepEngine/NanorepEngine.h>
#import "NRDefaultViewAdapter.h"



@interface NRResult : NSObject
- (instancetype)initWithResult:(NRQueryResult *)queryResult;
@property (nonatomic, readonly) NRQueryResult *queryResult;
@property (nonatomic, getter=isSingle) BOOL single;
@property (nonatomic, getter=isUnfolded) BOOL unfolded;
@property (nonatomic) CGFloat height;
@property (nonatomic, copy) NSString *accountName;
@property (nonatomic, copy) NSString *kb;
@property (nonatomic) CGFloat y;
@property (nonatomic) NRDefaultViewAdapter *viewAdapter;
@end
