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
    static var accountParamsPath: String?
    struct accountParamsKeys {
        static let Account = "account"
        static let KnowledgeBase = "knowledgeBase"
        static let ApiKey = "apiKey"
        static let NanorepContext = "nanorepContext"
        static let ChatContentURL = "chatContentURL"
        static let Server = "server"
    }
    
    static func getAcountParamsPath(_ fileName: String) -> String? {
        return Bundle.main.path(forResource: fileName, ofType: "plist")
    }
    
    static func getLocalParams() -> [String: String] {
        if let paramsPath  = getAcountParamsPath("MyAccountParams") {
            accountParamsPath = paramsPath
        } else {
            accountParamsPath = getAcountParamsPath("AccountParams")
        }
       
        return NSDictionary(contentsOfFile: accountParamsPath!)! as! [String : String]
    }
}
