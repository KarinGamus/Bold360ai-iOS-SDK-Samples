// ===================================================================================================
// Copyright © 2018 nanorep.
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

import UIKit
import NanorepUI

class ViewController: UIViewController, NRChatEngineDelegate, NRApplicationContentHandler,  HistoryProvider {
    
    private let accountParams = AccountParams()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func viewDidAppear(_ animated: Bool) {
        self.accountParams.account = ""
        self.accountParams.knowledgeBase = ""
        self.accountParams.apiKey = ""
    }
    
    var controller: NRConversationalViewController!
    
    @IBAction func loadNanorep(_ sender: UIButton) {
        // Set config
        let config: NRBotConfiguration = NRBotConfiguration()
        config.chatContentURL = URL(string: "")
        config.chatElementMaxLength = 620;
        config.withNavBar = true
        // Create NRConversationalViewController
        controller = NRConversationalViewController(accountParams: self.accountParams)
        controller.configuration = config
        // Set handlers & delegate
        self.setHandlers()
        
        self.present(controller, animated: true, completion: nil)
    }
    
    func setHandlers() {
        controller.delegate = self
        controller.historyProvider = self
//        controller.customChatContentHandler = self
        controller.applicationContentHandler = self
    }
    
    /************************************************************/
    // MARK: - NRChatEngineDelegate
    /************************************************************/
    
    func didFetchConvesationId(_ conversationId: NSNumber!) {
    }
    
    func shouldHandleMissingEntities(_ response: NRConversationalResponse!, missingEntitiesHandler handler: ((NRConversationMissingEntity?) -> Void)!) {
    }
    
    func shouldHandlePersonalInformation(_ personalInfo: NRPersonalInfo!) {
    }
    
    /************************************************************/
    // MARK: - NRApplicationContentHandler
    /************************************************************/
    
    func presenting(_ controller: UIViewController!, shouldHandleClickedLink link: String!) -> Bool {
        return true
    }
    
    func didClick(toCall phoneNumber: String!) {
    }
    
    func didClickLink(_ url: String!) {
    }
    
    func didSessionExpire() {
    }
    
    func controller(_ controller: NRConversationalViewController!, didClickApplicationQuickOption quickOption: NRQuickOption!) {
    }
    
    /************************************************************/
    // MARK: - NRCustomContentHandler
    /************************************************************/
    
    func chatReady(_ controller: NRConversationalViewController!) {
    }
    
    func controller(_ controller: NRConversationalViewController!, didSendStatement statement: String!) {
    }
    
    func controller(_ controller: NRConversationalViewController!, didStartCustomChatProvider chatProviderId: String!, query: String!) {
    }
    
    func controller(_ controller: NRConversationalViewController!, didFailWithError error: Error!) {
    }
    
    func controller(_ controller: NRConversationalViewController!, didRequestShare shareText: String!) {
    }
    
    func controller(_ controller: NRConversationalViewController!, didRequestLocation locationHandler: ((Double, Double) -> Void)!) {
    }
    
    /************************************************************/
    // MARK: - HistoryProvider
    /************************************************************/
    
    var historyElements = [String: Array<StorableChatElement>]()
    
    func fetch(_ from: Int, handler: (([Any]?) -> Void)!) {
    }
    
    func store(_ item: StorableChatElement!) {
    }
    
    func remove(_ timestampId: TimeInterval) {
    }
    
    func update(_ timestampId: TimeInterval, newTimestamp: TimeInterval, status: StatementStatus) {
    }
}
