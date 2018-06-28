// ===================================================================================================
// Copyright © 2018 nanorep.
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

import UIKit

class ViewController: UIViewController, NRChatEngineDelegate, NRApplicationContentHandler, NRCustomContentHandler {
    var accountParams: AccountParams!
    var conversationId: NSNumber!
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    @IBAction func loadNanorep(_ sender: UIButton) {
        accountParams = AccountParams.init()
        accountParams.account = "{account_name}"
        accountParams.knowledgeBase = "{knowledge_base}"
        accountParams.apiKey = "{api_key}"
        accountParams.nanorepContext = ["{nanorep_context}"]
        let entities = ["{entities}"];
        let config: NRBotConfiguration = NRBotConfiguration.init()
        config.resources.rootPath = "{root_path}"
        config.resources.webResources = ["{web_resources}"]
        config.entities = entities
        let controller: NRConversationalViewController = NRConversationalViewController.init(accountParams: self.accountParams)
        controller.customChatContentHandler = self
        controller.applicationContentHandler = self
        controller.conversationId = self.conversationId
        controller.configuration = config
        controller.delegate = self
        self.present(controller, animated: true, completion: nil)
    }
    
    
    // MARK: NRChatEngineDelegate
    func didFetchConvesationId(_ conversationId: NSNumber!) {
        self.conversationId = conversationId
    }
    
    func shouldHandleMissingEntities(_ response: NRConversationalResponse!, missingEntitiesHandler handler: ((NRConversationMissingEntity?) -> Void)!) {
        let answer: NRConversationMissingEntity = NRConversationMissingEntity.init(statement: response.statement)!
        for missingEntity: String in response.missingEntities! {
            let entity: NREntity = NREntity.init()
            switch missingEntity {
            case "BANK_USER":
                entity.lifecycle = EntityLifecyclePersistent
                entity.type = EntityTypeText
                entity.value = "Dipti"
                entity.confidence = 1
                answer.add(entity)
                break
            case "USER_ACCOUNTS":
                entity.lifecycle = EntityLifecyclePersistent
                entity.type = EntityTypeNumber
                entity.value = "3"
                entity.kind = missingEntity
                entity.confidence = 1
                for i in 0...3 {
                    let property: Property = Property.init()
                    property.kind = "ACCOUNT"
                    property.type = EntityTypeText
                    property.value = " " + String(i) + "123"
                    property.name = property.value
                    let type: Property = Property.init()
                    type.kind = "TYPE"
                    type.type = EntityTypeText
                    type.value = "Some Value"
                    property.add(type)
                    let currency: Property = Property.init()
                    currency.kind = "CURRENCY"
                    currency.type = EntityTypeText
                    currency.value = "$"
                    property.add(currency)
                    let accountId: Property = Property.init()
                    accountId.kind = "ID"
                    accountId.type = EntityTypeText
                    accountId.value = " " + String(i) + "123"
                    property.add(accountId)
                    entity.add(property)
                }
                answer.add(entity)
                break
            case "USER_CREDIT_CARDS":
                entity.lifecycle = EntityLifecyclePersistent
                entity.type = EntityTypeNumber
                entity.value = "3"
                entity.kind = missingEntity
                entity.confidence = 1
                for i in 0...3 {
                    let property: Property = Property.init()
                    property.kind = "CREDIT_CARD"
                    property.type = EntityTypeText
                    property.value = " " + String(i) + "123"
                    property.name = property.value
                    let type: Property = Property.init()
                    type.kind = "TYPE"
                    type.type = EntityTypeText
                    type.value = "Some Value"
                    property.add(type)
                    let currency: Property = Property.init()
                    currency.kind = "CURRENCY"
                    currency.type = EntityTypeText
                    currency.value = "$"
                    property.add(currency)
                    let accountId: Property = Property.init()
                    accountId.kind = "ID"
                    accountId.type = EntityTypeText
                    accountId.value = " " + String(i) + "123"
                    property.add(accountId)
                    entity.add(property)
                }
                answer.add(entity)
                break
            default:
                break
            }
        }
        handler(answer)
    }
    
    func shouldHandlePersonalInformation(_ personalInfo: NRPersonalInfo!) {
        personalInfo.personalInfoCallback!("1000 $", nil)
    }

    // MARK: NRApplicationContentHandler
    func didClickLink(_ url: String!) {
        print(url)
    }
    
    func didSessionExpire() {
    }
    
    // MARK: NRCustomContentHandler
    func controller(_ controller: NRConversationalViewController!, didSendStatement statement: String!) {
        if (statement == "stop") {
            controller.enableCustomContent = false
        }
    }
    
    func controller(_ controller: NRConversationalViewController!, didStartCustomChatProvider chatProviderId: String!) {
        let welcome: NRQuickOptionWrapper = NRQuickOptionWrapper.init()
        welcome.text = "Welcome to custom content";
        controller.injectQuickOption(welcome)
    }
}

