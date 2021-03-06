/*
 * This is the source code of Telegram for iOS v. 1.1
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Peter Iakovlev, 2013.
 */

#import "TGViewController.h"

#import "ActionStage.h"

#import "TGImagePickerAsset.h"

#ifdef __cplusplus
extern "C" {
#endif

void dispatchOnAssetsProcessingQueue(dispatch_block_t block);
void sharedAssetsLibraryRetain();
void sharedAssetsLibraryRelease();
    
#ifdef __cplusplus
}
#endif

@protocol TGImagePickerControllerDelegate;

@interface TGImagePickerController : TGViewController <ASWatcher, TGViewControllerNavigationBarAppearance>

+ (id)sharedAssetsLibrary;
+ (id)preloadLibrary;
+ (void)loadAssetWithUrl:(NSURL *)url completion:(void (^)(ALAsset *asset))completion;
+ (void)storeImageAsset:(NSData *)data;

@property (nonatomic, strong) ASHandle *actionHandle;

@property (nonatomic, weak) id<TGImagePickerControllerDelegate> delegate;

- (id)initWithGroupUrl:(NSURL *)groupUrl groupTitle:(NSString *)groupTitle avatarSelection:(bool)avatarSelection;

@end

@protocol TGImagePickerControllerDelegate <NSObject>

- (void)imagePickerController:(TGImagePickerController *)imagePicker didFinishPickingWithAssets:(NSArray *)assets;

@end