//
// Created by majiancheng on 2017/3/17.
// Copyright (c) 2017 mjc inc. All rights reserved.
//



#import "MCPlayerBaseView.h"

typedef void(^MCPlayerNormalViewEventCallBack)(NSString *action, id value);

typedef NS_ENUM(NSInteger, MCPlayerStyleSizeType) {
    PlayerStyleSizeClassRegularHalf,   ///<  16:9 半屏幕
    PlayerStyleSizeClassRegular,       ///<  竖屏全屏
    PlayerStyleSizeClassCompact        ///<  横屏全屏
};

/***
 * 通用播放器view
 */
@interface MCPlayerNormalView : UIView

@property(nonatomic, copy) MCPlayerNormalViewEventCallBack eventCallBack;

- (void)updatePlayerStyle:(MCPlayerStyleSizeType)styleSizeType;


@end
