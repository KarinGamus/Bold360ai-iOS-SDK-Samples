// ===================================================================================================
// Copyright © 2018 nanorep.
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

import UIKit
import NanorepUI

class ViewController: UITableViewController, NanorepViewAdapter {
    
    var labels: [VFLabel] = []
    var state: Bool = false
    
    // Nanorep's account params
    var accountParams: AccountParams!
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        let path = Bundle.main.path(forResource: "vfLabels", ofType: "json")
        let data = try? NSData(contentsOfFile: path!, options: NSData.ReadingOptions.mappedIfSafe)
        let tempLabels = try! JSONSerialization.jsonObject(with: data! as Data, options: JSONSerialization.ReadingOptions.mutableContainers) as! [[String: String]]
        for i in 0...tempLabels.count - 1 {
            self.labels.append(VFLabel(params: tempLabels[i]))
            ImageFetcher.fetchImage(url: URL.init(string: self.labels[i].icon)!, index: i, completion: { (image: UIImage?, index: Int) in
                self.labels[index].img = image
                DispatchQueue.main.async {
                    self.tableView.reloadData()
                }
            })
        }
        
        // Init the account (you can add the context here)
        self.accountParams = AccountParams()
        self.accountParams.account = "{account_name}"
        self.accountParams.knowledgeBase = "{knowledge_base}"
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.labels.count
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell: VFLabelTableViewCell = tableView.dequeueReusableCell(withIdentifier: "cell", for: indexPath) as! VFLabelTableViewCell
        cell.label = self.labels[indexPath.row]
        return cell
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        // Change the label 
        self.accountParams.labelId = self.labels[indexPath.row].id
        NanoRep.shared().prepare(with: self.accountParams)
        NanoRep.shared().fetchConfiguration = {
            (configuration: NRConfiguration?, error: Error?) -> Void in
            configuration?.autoComplete.withDivider = true
            configuration?.logo.hideBranding = true
            configuration?.title.font = UIFont.boldSystemFont(ofSize: 18.0)
            configuration?.navBar.backgroundColor = UIColor.red
            DispatchQueue.main.async {
                let widget: NRWidgetViewController = NRWidgetViewController()
                if self.state {
                    widget.viewAdapter = self
                }
                //                widget.disableNavigation = true
                self.navigationController?.pushViewController(widget, animated: true)
            }
        }
    }
    
    @IBAction func toggleCustomViews(_ sender: UIBarButtonItem) {
        state = !state
        if state {
            sender.title = "Custom"
        } else {
            sender.title = "Default"
        }
    }
    
    // MARK: NRViewAdapter 
    
    var customSearchBar: UIView {
        return CustomSearchBar.init(frame: CGRect.init(origin: CGPoint.zero, size: CGSize.init(width: self.view.frame.size.width, height: 60.0)))
    }
    
    var feedbackView: UIView! {
        return CustomFeedbackView.init(frame: CGRect.init(origin: CGPoint.zero, size: CGSize.init(width: self.view.frame.size.width, height: 200.0)))
    }
}

