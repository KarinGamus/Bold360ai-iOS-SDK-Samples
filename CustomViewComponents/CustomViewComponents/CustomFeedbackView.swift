// ===================================================================================================
// Copyright © 2018 nanorep.
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

import UIKit

class CustomFeedbackView: UIView, NRFeedbackView {
    @NSCopying var initialState: NSNumber!

    
    @IBOutlet weak var yesButton: UIButton!
    @IBOutlet weak var noButton: UIButton!
    @IBOutlet weak var channelButton: UIButton!
    @IBOutlet weak var notHelpfulLabel: UILabel!
    
    
    var channels: [NRChanneling]! {
        willSet {
            self.channelButton.setTitle(newValue.first?.buttonText, for: UIControlState.normal)
        }
    }
    var feedbackDelegate: NRFeedbackViewDelegate!
    var likeDelegate: NRLikeViewDelegate!
    
    
    
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        let contentView: UIView = Bundle.main.loadNibNamed("CustomFeedbackView", owner: self, options: nil)?.first as! UIView
        contentView.frame = frame
        self.yesButton.layer.cornerRadius = 5.0;
        self.yesButton.layer.borderColor = self.yesButton.titleLabel?.textColor.cgColor;
        self.yesButton.layer.borderWidth = 1.0;
        self.noButton.layer.cornerRadius = 5.0;
        self.noButton.layer.borderColor = self.noButton.titleLabel?.textColor.cgColor;
        self.noButton.layer.borderWidth = 1.0;
        self.addSubview(contentView)
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    @IBAction func feedback(_ sender: UIButton) {
        self.feedbackDelegate.didLikePressed(sender.tag == 0)
        let disableColor: UIColor = UIColor.init(red: 200.0/255.0,
                                                 green: 199.0/255.0,
                                                 blue: 204.0/255.0,
                                                 alpha: 1)
        if sender.tag == 0 {
            self.notHelpfulLabel.isHidden = false
            self.channelButton.isHidden = false
            let redColor = UIColor.init(red: 1,
                                        green: 82.0/255.0,
                                        blue: 82.0/255.0,
                                        alpha: 1)
            self.noButton.layer.borderColor = redColor.cgColor
            self.noButton.setTitleColor(redColor, for: UIControlState.disabled)
            self.yesButton.layer.borderColor = disableColor.cgColor
        } else {
            let greenColor = UIColor.init(red: 96.0/255.0,
                                          green: 195.0/255.0,
                                          blue: 0,
                                          alpha: 1)
            self.noButton.layer.borderColor = disableColor.cgColor
            self.yesButton.layer.borderColor = greenColor.cgColor
            self.yesButton.setTitleColor(greenColor, for: UIControlState.disabled)
        }
        self.noButton.isEnabled = false
        self.yesButton.isEnabled = false
    }

    @IBAction func channelClicked(_ sender: UIButton) {
        self.feedbackDelegate.didSelectChannel(self.channels.first)
    }
    
    func updateLikeButton(_ isLike: Bool) {
        if isLike {
            self.notHelpfulLabel.text = "Thanks for your feedback"
            self.notHelpfulLabel.isHidden = false
        }
    }
    
    func reset() {
        
    }
    
    func cancel() {
        
    }
    
    

}
