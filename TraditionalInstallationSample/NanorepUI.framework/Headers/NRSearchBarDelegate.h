
// NanorepUI version number: v1.6.1 

//
//  NRSearchBarDelegate.h
//  NanoRepWidget
//
//  Created by Nissim Pardo on 27/10/2016.
//  Copyright © 2016 nanorep. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol NRSearchBarDelegate <NSObject>
- (void)fetchSuggestions:(NSString *)text;
- (void)search:(NSString *)text;
- (void)clear;
- (void)removeSuggestions;
@end
