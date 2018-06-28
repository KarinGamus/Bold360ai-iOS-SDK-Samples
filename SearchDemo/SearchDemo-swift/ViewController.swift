// ===================================================================================================
// Copyright © 2018 nanorep.
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

import UIKit
import NanorepUI

class ViewController: UIViewController, NanorepPersonalInfoHandler, UITextFieldDelegate, NRApplicationContentHandler, NRReadMoreViewControllerDelegate  {
    
    /************************************************************/
    // MARK: - Properties
    /************************************************************/
    
    // Outlets
    @IBOutlet weak var kbTF: UITextField!
    @IBOutlet weak var accountTF: UITextField!
    @IBOutlet weak var phoneConfirmation: UISwitch!
    @IBOutlet weak var articleIdTF: UITextField!
    @IBOutlet weak var appVersionLabel: UILabel!
    @IBOutlet weak var sdkVersion: UILabel!
    
    // Params
    var widgetController: NRWidgetViewController!
    
    /************************************************************/
    // MARK: - Functions
    /************************************************************/

    override func viewDidLoad() {
        super.viewDidLoad()
        self.appVersionLabel.text = appVersionLabel.text! + (Bundle.main.infoDictionary?["CFBundleShortVersionString"] as? String ?? "")
        self.sdkVersion.text = sdkVersion.text! + (Bundle.sdkVersion())
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    
    @IBAction func loadNanorep(_ sender: Any) {
        self.view.endEditing(true)
        
        let accountParams = AccountParams()
        accountParams.account =  self.accountTF.text
        accountParams.knowledgeBase = self.kbTF.text
//        accountParams.perform(Selector("setServer:"), with: "qa09")
        NanoRep.shared().prepare(with: accountParams)
        
        NanoRep.shared().fetchConfiguration = {
            (configuration: NRConfiguration?, error: Error?) -> Void in
            
            if error != nil {
                print(error.debugDescription)
            }

            configuration?.useLabels = true
            DispatchQueue.main.async { [unowned self] in
                self.widgetController = NRWidgetViewController()
                self.widgetController.infoHandler = self
                self.present(self.widgetController, animated: true, completion: nil)
//                self.widgetController.view.frame = CGRect(origin: CGPoint.zero, size: CGSize(width: self.view.frame.size.width, height: self.view.frame.size.height - 44.0))
//                self.addChildViewController(self.widgetController)
//                self.view.addSubview(self.widgetController.view)
            }
        }
    }

    /************************************************************/
    // MARK: - NRReadMoreViewControllerDelegate
    /************************************************************/
    
    
    func shouldOverridePhoneChannel(_ phoneChannel: NRChannelingPhoneNumber!) -> Bool {
        if self.phoneConfirmation.isOn {
            let alert = UIAlertController(title: "Phone Confirmation", message: "Need your approval for dialing number :\n" + (phoneChannel?.phoneNumber ?? ""), preferredStyle: .alert)
            let action = UIAlertAction(title: "Approve", style: .default, handler: nil)
            alert.addAction(action)
            widgetController.present(alert, animated: true)
        }
        return phoneConfirmation.isOn
    }
    
//    func shouldPresentConfirmationPopup(forChannel channel: NRChanneling!) -> Bool {
//        return true
//    }

    
    func presentFileList(_ files: [String]?) {
        let alert = UIAlertController(title: "Files To Upload", message: nil, preferredStyle: .actionSheet)
        for key: String? in files ?? [String?]() {
            alert.addAction(UIAlertAction(title: key, style: .default, handler: { action in
            }))
        }
        widgetController.present(alert, animated: true)
    }
    
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        // Deep link example
        let account = AccountParams()
        account.account = accountTF.text
        account.knowledgeBase = kbTF.text
        NanoRep.shared().prepare(with: account)
        weak var weakSelf: ViewController? = self
        NanoRep.shared().fetchConfiguration = { config, err in
            if (err != nil) {
                print("ERROR ::\(String(describing: err))")
            } else {
                DispatchQueue.main.async(execute: {
                    let deepLink = NRReadMoreViewController()
                    deepLink.infoHandler = self
                    deepLink.articleId = textField.text
                    deepLink.applicationHandler = weakSelf
                    let navController = UINavigationController(rootViewController: deepLink)
                    navController.navigationBar.topItem?.rightBarButtonItem = UIBarButtonItem(barButtonSystemItem: .stop, target: self, action: #selector(self.dismissDeeplinkPage(_:)))
                    weakSelf?.present(navController, animated: true)
                })
            }
        }
        
        return true
    }
    
    func readmoreController(_ readmoreController: NRReadMoreViewController!, presentModally controller: UIViewController!) {
        if let aController = controller {
            readmoreController?.navigationController?.present(aController, animated: true)
        }
    }
    
    @objc func dismissDeeplinkPage(_ sender: UIBarButtonItem?) {
        ((self.presentedViewController as! UINavigationController).viewControllers.first as! NRReadMoreViewController).dismiss()
        self.presentedViewController?.dismiss(animated: true, completion: {
            
        })
    }
    
    func presenting(_ controller: UIViewController!, shouldHandleClickedLink link: String!) -> Bool {
        return true
    }
    
    func didSubmitFeedback(_ info: [AnyHashable : Any]!) {}
    func didClick(toCall phoneNumber: String!) {}
    func didClickLink(_ url: String!) {}
    func didSessionExpire() {}
    
    func didFetch(_ formData: ExtraData!) {
        print("didFetchExtraData")
        for value in formData.values {
            print(value.value)
        }
    }
    
    func didSubmitForm() {
        print("didSubmitForm")
    }
    
    func didCancelForm() {
        print("didCancelForm")
    }
    
    func personalInfo(withExtraData extraData: [AnyHashable : Any]!, channel: NRChanneling!, completionHandler handler: (([AnyHashable : Any]?) -> Void)!) {
//        var temp = extraData!
//        temp["Testing"] = "working"
        handler(extraData)
        print("personalInfo")
    }
    
    
    func didFailSubmitFormWithError(_ error: Error!) {
        
    }
    func controller(_ controller: NRConversationalViewController!, didClickApplicationQuickOption quickOption: NRQuickOption!) {}
}
