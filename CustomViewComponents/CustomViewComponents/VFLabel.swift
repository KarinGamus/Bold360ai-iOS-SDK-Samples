// ===================================================================================================
// Copyright © 2018 nanorep.
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

import UIKit

class VFLabel: NSObject {
    var id: String!
    var icon: String!
    var name: String!
    var img: UIImage!
    
    init(params: [String: String]) {
        self.id = params["id"]
        self.icon = params["icon"]
        self.name = params["name"]
    }
}
