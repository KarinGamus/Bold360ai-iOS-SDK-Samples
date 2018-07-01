
// NanorepUI version number: v1.5.6.1 

//
//  NRTokenizer.h
//  ConversationEngine
//
//  Created by Nissim Pardo on 08/05/2017.
//  Copyright © 2017 nanorep. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NRTokenizer : NSObject
- (NSString *)encode:(NSString *)statement;
- (NSString *)decode:(NSString *)statement;
@end
