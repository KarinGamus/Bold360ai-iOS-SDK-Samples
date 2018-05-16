// ===================================================================================================
// Copyright © 2018 nanorep.
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

import UIKit

class ImageFetcher: NSObject {
    static func fetchImage(url: URL, index: Int, completion: @escaping (_ image: UIImage?, _ i: Int) -> Void) -> Void {
        let sessionConfiguration = URLSessionConfiguration.default
        let session = URLSession.init(configuration: sessionConfiguration)
        let task = session.dataTask(with: url) { (data:Data?, response:URLResponse?, error:Error?) in
            if data != nil {
                if let image: UIImage = UIImage.init(data: data!) {
                    completion(image, index)
                } else {
                    completion(nil, index)
                }
            } else {
                completion(nil, index)
            }
        }
        task.resume()
    }
}
