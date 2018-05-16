// ===================================================================================================
// Copyright © 2018 nanorep.
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

import UIKit

class VFLabelTableViewCell: UITableViewCell {
    var label: VFLabel {
        set {
            if let image = newValue.img {
                self.icon.image = image
            }
            labelName.text = newValue.name
        } get {
            return self.label
        }
    }
    
    @IBOutlet weak var icon: UIImageView!
    @IBOutlet weak var labelName: UILabel!

    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    
}
