







#import <UIKit/UIKit.h>
@class SDMailBoxTextView;

NS_ASSUME_NONNULL_BEGIN

@protocol SDMailBoxTextViewDelegate <NSObject>

@optional
///开始输入
- (void)textViewBeginEditing:(SDMailBoxTextView *)texteView;
///结束输入
- (void)textViewEndEditing:(SDMailBoxTextView *)texteView;
///输入改变
- (void)textViewDidChange:(SDMailBoxTextView *)texteView;

@end

@interface SDMailBoxTextViewConfigure : NSObject

///匹配邮箱数组
@property (nonatomic, strong) NSArray<NSString *> *mailMatchingArray;
///边距
@property (nonatomic, assign) UIEdgeInsets edgeInsets;
///字体大小
@property (nonatomic, strong) UIFont *font;
/** 占位文字 */
@property (nonatomic, copy) NSString *placeholder;
///输入文字颜色
@property (nonatomic, strong) UIColor *textColor;
///补全后缀文字颜色
@property (nonatomic, strong) UIColor *suffixColor;

@end


@interface SDMailBoxTextView : UIView
///代理
@property (nonatomic, weak) id<SDMailBoxTextViewDelegate> delegate;
///输入的文字
@property (nonatomic, copy, readonly, nullable) NSString *text;

///更新基本配置，block不会造成循环引用
- (void)updateWithConfigure:(void(^)(SDMailBoxTextViewConfigure *configure))configureBlock;

///清除文字
- (void)clearText;


@end

NS_ASSUME_NONNULL_END
