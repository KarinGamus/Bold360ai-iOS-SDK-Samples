
// NanorepUI version number: v1.5.8.rc2 

//
//  NSURLRequest+Channeling.h
//  NanoRepWidget
//
//  Created by Nissim Pardo on 26/02/2016.
//  Copyright © 2016 nanorep. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSURLRequest (Channeling)
@property (nonatomic, readonly) BOOL isNanorep;
@property (nonatomic, readonly) NSInteger type;
@property (nonatomic, copy, readonly) NSString *result;
@property (nonatomic, copy, readonly) NSDictionary *formData;
@end
