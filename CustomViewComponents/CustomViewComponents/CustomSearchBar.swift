// ===================================================================================================
// Copyright © 2018 nanorep.
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

import UIKit


class CustomSearchBar: UIView, NRSearchBar, UITextFieldDelegate {
    
    @IBOutlet var delegate: NRSearchBarDelegate!
    
    var hint: String {
        set {
            self.searchTextField.text = newValue
        }
        get {
            return self.searchTextField.text!
        }
    }
    
    @IBOutlet weak var searchBarContainer: UIView!
    @IBOutlet weak var cancelButton: UIButton!
    @IBOutlet weak var searchTextField: UITextField!
    @IBOutlet weak var containerTrailing: NSLayoutConstraint!
    @IBOutlet weak var clearButton: UIButton!
    var containerTrailingInitial: CGFloat!
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        let contentView: UIView = Bundle.main.loadNibNamed("CustomSearchBar",
                                                   owner: self,
                                                   options: nil)?.first as! UIView
        contentView.frame = self.bounds
        self.searchBarContainer.layer.cornerRadius = 5.0
        let containerColor: UIColor = UIColor.init(red: 200.0/255.0,
                                                   green: 199.0/255.0,
                                                   blue: 204.0/255.0,
                                                   alpha: 1)
        self.searchBarContainer.layer.borderColor = containerColor.cgColor
        self.searchBarContainer.layer.borderWidth = 1.0
        self.containerTrailingInitial = self.containerTrailing.constant
        self.addSubview(contentView)
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    @IBAction func clearText(_ sender: UIButton!) {
        if sender != nil && sender.isSelected {
            self.searchTextField.text = ""
            sender.isSelected = false
            self.delegate.removeSuggestions()
        }
    }
    
    func dismissKeyboard() {
        
    }
    
    @IBAction func cancel(_ sender: UIButton) {
        self.containerTrailing.constant -= self.cancelButton.frame.size.width
        self.clearButton.isSelected = false
        self.searchTextField.text = ""
        self.searchTextField.resignFirstResponder()
        self.delegate.clear()
    }
    
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        self.delegate.search(textField.text)
        return true
    }
    
    func textFieldDidBeginEditing(_ textField: UITextField) {
        if self.containerTrailing.constant == self.containerTrailingInitial {
            self.containerTrailing.constant += self.cancelButton.frame.size.width
        }
    }
    
    func textField(_ textField: UITextField, shouldChangeCharactersIn range: NSRange, replacementString string: String) -> Bool {
        self.clearButton.isSelected = (textField.text?.characters.count)! + string.characters.count > 0
        self.delegate.fetchSuggestions(textField.text! + string)
        return true
    }
    

}
