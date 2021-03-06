/*
 * This is the source code of Telegram for iOS v. 1.1
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Peter Iakovlev, 2013.
 */

#import <UIKit/UIKit.h>

#import "ActionStage.h"

#import "TGViewController.h"

extern NSString *authorNameYou;

@class TGDialogListCompanion;

@interface TGDialogListController : TGViewController <ASWatcher>

@property (nonatomic, strong, readonly) ASHandle *actionHandle;

@property (nonatomic, strong) TGDialogListCompanion *dialogListCompanion;

@property (nonatomic) bool canLoadMore;

@property (nonatomic) bool doNotHideSearchAutomatically;

+ (void)setLastAppearedConversationId:(int64_t)conversationId;

+ (void)setDebugDoNotJump:(bool)debugDoNotJump;
+ (bool)debugDoNotJump;

- (id)initWithCompanion:(TGDialogListCompanion *)companion;

- (void)resetState;
- (void)dialogListFullyReloaded:(NSArray *)items;
- (void)dialogListItemsChanged:(NSArray *)insertedIndices insertedItems:(NSArray *)insertedItems updatedIndices:(NSArray *)updatedIndices updatedItems:(NSArray *)updatedItems removedIndices:(NSArray *)removedIndices;

- (void)selectConversationWithId:(int64_t)conversationId;

- (void)searchResultsReloaded:(NSArray *)items searchString:(NSString *)searchString;

- (void)titleStateUpdated:(NSString *)text isLoading:(bool)isLoading;

- (void)userTypingInConversationUpdated:(int64_t)conversationId typingString:(NSString *)typingString;

@end
