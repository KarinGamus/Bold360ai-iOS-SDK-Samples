// ===================================================================================================
// Copyright © 2018 nanorep.
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

import Foundation

/************************************************************/
// MARK: - AccountParamsHelper
/************************************************************/

class AccountParamsHelper {
    struct accountParamsKeys {
        static let Account = "account"
        static let KnowledgeBase = "knowledgeBase"
        static let ApiKey = "apiKey"
        static let NanorepContext = "nanorepContext"
        static let ChatContentURL = "chatContentURL"
        static let Server = "server"
    }
    
    static func getLocalParams() -> NSDictionary {
        let accountParamsPath = Bundle.main.path(forResource: "AccountParams", ofType: "plist")
       
        return NSDictionary(contentsOfFile: accountParamsPath!)!
    }
}

/************************************************************/
// MARK: - NSDictionary Extensions
/************************************************************/

extension NSDictionary {
    func value(forKey keyPath: String) -> String? {
        return super.value(forKey: keyPath) as? String
    }
    
    func value(forKey keyPath: String) -> [String: String]? {
        return super.value(forKey: keyPath) as? [String : String]
    }
}
