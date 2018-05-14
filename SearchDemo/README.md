# NanorepUI
Nanorep Widget SDK

##How to implement Nanorep SDK:

1. Run `pod install`/ `pod update`
2. Open generated `.xcworkspace` file with Xcode
3. Run on simulator or device.


##How to use the SDK:
If you are using swift you will need to add `Bridging-Header` you can learn about it here:
[Bridging header](https://developer.apple.com/library/content/documentation/Swift/Conceptual/BuildingCocoaApps/MixandMatch.html)


In the view controller which should present the NanoRep view controller you should add:

```swift
@IBAction func presentNanorep(_ sender: UIButton) {
        NanoRep.shared().prepare(with: self.accountParams)
        NanoRep.shared().fetchConfiguration = {
            (configuration: NRConfiguration?, error: Error?) -> Void in
            DispatchQueue.main.async {
                let widget: NRWidgetViewController = NRWidgetViewController()
                self.navigationController?.pushViewController(widget, animated: true)
            }
        }
    }
```

For advanced features:
[Nanorep Wiki](https://github.com/nanorepsdk/NanorepUI/wiki)

## License

See [License and Copyright Information](https://github.com/nanorepsdk/NRSDK-iOS-Samples#license-and-copyright-information)