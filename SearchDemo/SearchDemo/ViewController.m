// ===================================================================================================
// Copyright © 2018 nanorep.
// NanorepUI SDK.
// All rights reserved.
// ===================================================================================================

#import "ViewController.h"
#import "NanorepUI.h"

@interface ViewController () <NanorepPersonalInfoHandler, UITextFieldDelegate, NRApplicationContentHandler, NRReadMoreViewControllerDelegate>
@property (weak, nonatomic) IBOutlet UITextField *kbTF;
@property (weak, nonatomic) IBOutlet UITextField *accountTF;
@property (weak, nonatomic) IBOutlet UISwitch *phoneConfirmation;
@property (nonatomic, strong) NRWidgetViewController *widgetController;
@property (weak, nonatomic) IBOutlet UITextField *articleIdTF;
@property (weak, nonatomic) IBOutlet UILabel *appVersionLabel;
@property (weak, nonatomic) IBOutlet UILabel *sdkVersion;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    _appVersionLabel.text = [_appVersionLabel.text stringByAppendingString:[[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]];
    _sdkVersion.text = [_sdkVersion.text stringByAppendingString:[NSBundle sdkVersion]];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (IBAction)loadNanorep:(UIButton *)sender {
    AccountParams *account = [AccountParams new];
    account.account = _accountTF.text;
    account.knowledgeBase = _kbTF.text;
    
//    account.nanorepContext =  @{@"DeviceType": @"iOS"};
    [[NanoRep shared] prepareWithAccountParams:account];
    __weak ViewController *weakSelf = self;
    [NanoRep shared].fetchConfiguration = ^(NRConfiguration *config, NSError *err) {
        if (err) {
            NSLog(@"ERROR ::%@", err);
        } else {
            dispatch_async(dispatch_get_main_queue(), ^{
                weakSelf.widgetController = [NRWidgetViewController new];
                weakSelf.widgetController.infoHandler = weakSelf;
                [weakSelf presentViewController:weakSelf.widgetController animated:YES completion:nil];
            });
        }
    };
}

- (BOOL)shouldOverridePhoneChannel:(NRChannelingPhoneNumber *)phoneChannel {
    if (_phoneConfirmation.isOn) {
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Phone Confirmation" message:[@"Need your approval for dialing number :\n" stringByAppendingString:phoneChannel.phoneNumber] preferredStyle:UIAlertControllerStyleAlert];
        UIAlertAction *action = [UIAlertAction actionWithTitle:@"Approve" style:UIAlertActionStyleDefault handler:nil];
        [alert addAction:action];
        [_widgetController presentViewController:alert animated:YES completion:nil];
    }
    return _phoneConfirmation.isOn;
}

- (void)personalInfoWithExtraData:(NSDictionary *)extraData
                          channel:(NRChanneling *)channel
                completionHandler:(void(^)(NSDictionary *formData))handler {
    handler(extraData);
}

- (void)didFetchExtraData:(ExtraData *)formData {
    
}


- (void)didSubmitForm {
    
}

- (void)didCancelForm {
    
}

- (void)presentFileList:(NSArray<NSString *> *)files {
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Files To Upload" message:nil preferredStyle:UIAlertControllerStyleActionSheet];
    for (NSString *key in files) {
        [alert addAction:[UIAlertAction actionWithTitle:key style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            
        }]];
    }
    [self.widgetController presentViewController:alert animated:YES completion:nil];
}

- (void)didFailSubmitFormWithError:(NSError *)error {
    
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    
    
    // Deep link example
    AccountParams *account = [AccountParams new];
    account.account = _accountTF.text;
    account.knowledgeBase = _kbTF.text;
    [[NanoRep shared] prepareWithAccountParams:account];
    __weak ViewController *weakSelf = self;
    [NanoRep shared].fetchConfiguration = ^(NRConfiguration *config, NSError *err) {
        if (err) {
            NSLog(@"ERROR ::%@", err);
        } else {
            dispatch_async(dispatch_get_main_queue(), ^{
                NRReadMoreViewController *deepLink = [NRReadMoreViewController new];
                deepLink.infoHandler = self;
                deepLink.delegate = self;
                deepLink.articleId = textField.text;
                deepLink.applicationHandler = weakSelf;
                UINavigationController *navController = [[UINavigationController alloc] initWithRootViewController:deepLink];
                navController.navigationBar.topItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemStop target:self action:@selector(dismissDeeplinkPage:)];
                [weakSelf presentViewController:navController animated:YES completion:nil];
            });
        }
    };
    return YES;
}

- (void)dismissDeeplinkPage:(UIBarButtonItem *)sender {
    [self.presentedViewController dismissViewControllerAnimated:YES completion:nil];
}

- (void)readmoreController:(NRReadMoreViewController *)readmoreController presentModally:(UIViewController *)controller {
    [readmoreController.navigationController presentViewController:controller animated:YES completion:nil];
}

@end
