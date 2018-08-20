// ===================================================================================================
// Copyright © 2018 nanorep.
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

import UIKit
import NanorepUI
import RealmSwift

/************************************************************/
// MARK: - ViewController
/************************************************************/

class ViewController: UIViewController {
    var delegate: ChatHandlerDelegate!
    
    var chatControllerDelegate: NRChatControllerDelegate!
    var chatHandlerProvider: ChatHandlerProvider!
    var historyElements = [String: Array<StorableChatElement>]()
    
    private var accountParams: AccountParams?
    var chatController: NRChatController!
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func loadNanorep(_ sender: UIButton) {
        let config: NRBotConfiguration = NRBotConfiguration()
        self.accountParams = self.setupAccountParams()
        self.chatController = NRChatController(account: self.accountParams)
        config.chatContentURL = URL.init(string:AccountParamsHelper.getLocalParams()[AccountParamsHelper.accountParamsKeys.ChatContentURL]!)
        config.withNavBar = true
        // TODO: under config pass id
        self.chatController.delegate = self
        self.chatController.handOver = self
        self.chatController.uiConfiguration = config
        self.chatController.historyProvider = self
        self.chatController.initialize = { controller, configuration, error in
            if let vc = controller {
                self.navigationController?.pushViewController(vc, animated: true)
            }
        }
        
    }
    
    func setupAccountParams() -> AccountParams {
        let params = AccountParams()
        let localAccountParams = AccountParamsHelper.getLocalParams()
        params.account = localAccountParams[AccountParamsHelper.accountParamsKeys.Account]
        params.knowledgeBase = localAccountParams[AccountParamsHelper.accountParamsKeys.KnowledgeBase]
        params.apiKey = localAccountParams[AccountParamsHelper.accountParamsKeys.ApiKey]
        params.nanorepContext = ["UserRole": AccountParamsHelper.accountParamsKeys.NanorepContext]
        params.perform(Selector.init(("setServer:")), with: localAccountParams[AccountParamsHelper.accountParamsKeys.Server])
        
        return params
    }
    
    @IBAction func deleteHistory(_ sender: Any) {
        DBManager.sharedInstance.deleteAllDatabase()
    }
    
    @objc func stopLiveChat(sender: UIBarButtonItem) {
        self.navigationController?.viewControllers.last?.navigationItem.setRightBarButton(nil, animated: true)
        self.navigationController?.viewControllers.last?.title = "Bye .."
        self.navigationController?.viewControllers.last?.perform(#selector(setter: UIViewController.title), with: nil, afterDelay: 2)
        self.chatHandlerProvider.didEndChat(self)
    }
}

/************************************************************/
// MARK: - ChatHandler
/************************************************************/

extension ViewController: ChatHandler {
    func startChat(_ chatInfo: [AnyHashable : Any]!) {
        self.navigationController?.viewControllers.last?.navigationItem.setRightBarButton(UIBarButtonItem(barButtonSystemItem: .stop, target: self, action: #selector(ViewController.stopLiveChat(sender:))), animated: true)
        self.navigationController?.viewControllers.last?.title = "You're talking with Nisso"
    }
    
    func endChat() {
        
    }
    
    func postStatement(_ statement: ChatElement!) {
        self.delegate.presentStatement(statement)
        let remote = RemoteChatElement(type: .RemoteElement, content: "Hello from Live Agent")
        remote?.design = ChatElementDesignCustomIncoming
        remote?.agentType = .Live
        self.delegate.presentStatement(remote)
    }
    
    func handleClickedLink(_ link: URL!) {
        
    }
    
    func handleEvent(_ eventParams: [AnyHashable : Any]!) {
        
    }
}

/************************************************************/
// MARK: - NRChatControllerDelegate
/************************************************************/

extension ViewController: NRChatControllerDelegate {
    
    func shouldHandleFormPresentation(_ formController: UIViewController!) -> Bool {
        return true
    }
    
    func didFailWithError(_ error: Error!) {
        
    }
    
    func didClickLink(_ url: String!) {
        if let link = URL(string: url.addingPercentEncoding(withAllowedCharacters: CharacterSet.urlPathAllowed)!) {
            
            if #available(iOS 10.0, *) {
                UIApplication.shared.open(link, options: [:], completionHandler: { (success) in
                    
                })
            } else {
                // Fallback on earlier versions
            }
        }
    }
    
    func didClick(toCall phoneNumber: String!) {
        let phoneNum = phoneNumber.replacingOccurrences(of: "[^0-9]", with: "", options: .regularExpression, range: nil)
        didClickLink("tel://" + phoneNum)
    }
    
    func presenting(_ controller: UIViewController!, shouldHandleClickedLink link: String!) -> Bool {
        return true
    }
}

/************************************************************/
// MARK: - HistoryProvider
/************************************************************/

extension ViewController: HistoryProvider {
    func fetch(_ from: Int, handler: (([Any]?) -> Void)!) {
        print("fetch")
        
        var elements: Array<StorableChatElement>!
        
        if(DBManager.sharedInstance.getDataFromDB().count > 0) {
            let items = DBManager.sharedInstance.getDataFromDB()
            //  let elements = historyElements.values.first
            
            elements = Array(items)
        }
        handler(elements)
    }
    
    func store(_ item: StorableChatElement) {
        print("store")
        
        let element = Item(item: item)
        element.ID = Int(DBManager.sharedInstance.getDataFromDB().count)
        DBManager.sharedInstance.addData(object: element)
    }
    
    func remove(_ timestampId: TimeInterval) {
        print("remove")
        
        DBManager.sharedInstance.deleteAllDatabase()
    }
    
    func update(_ timestampId: TimeInterval, newTimestamp: TimeInterval, status: StatementStatus) {
        print("update")
    }
}
