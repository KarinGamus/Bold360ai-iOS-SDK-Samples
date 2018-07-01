
// NanorepUI version number: v1.6.1 

//
//  NRDefaultViewAdapter.h
//  NanorepUI
//
//  Created by Nissim Pardo on 23/11/2016.
//  Copyright © 2016 nanorep. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NRAbstractViews.h"

@interface NRDefaultViewAdapter : NSObject <NanorepViewAdapter>
@property (nonatomic, weak) id<NanorepViewAdapter> appAdapter;
@end
