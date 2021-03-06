//
// Created by majiancheng on 2017/3/17.
// Copyright (c) 2017 mjc inc. All rights reserved.
//



#import "MCPlayerView.h"

#import "MCPlayerViewConfig.h"

@class MCPlayerKit;
@class MCPlayerGeneralHeader;
@class MCPlayerGeneralFooter;


extern NSString *const kMCPlayer2PlayAction;
extern NSString *const kMCPlayer2PauseAction;
extern NSString *const kMCTouchBegin;
extern NSString *const kMCTouchSeekAction;
extern NSString *const kMCTouchCurrentTimeAction;
extern NSString *const kMCTouchDurationAction;
extern NSString *const kMCControlProgressStartDragSlider;
extern NSString *const kMCDragProgressToProgress;
extern NSString *const kMCControlProgressEndDragSlider;
extern NSString *const kMCPlayerDestory;
extern NSString *const kMCPlayerStyleSizeClassRegularAction;
extern NSString *const kMCPlayerStyleSizeClassRegularHalfAction;

typedef NS_ENUM(NSInteger, MCPlayerStyleSizeType) {
    MCPlayerStyleSizeClassRegularHalf,   ///<  16:9 半屏幕
    MCPlayerStyleSizeClassRegular,       ///<  竖屏全屏
    MCPlayerStyleSizeClassCompact        ///<  横屏全屏
};

/***
 * 通用播放器view
 */
@interface MCPlayerGeneralView : UIView

@property(nonatomic, assign) MCPlayerStyleSizeType styleSizeType;
@property(nonatomic, readonly) MCPlayerView *playerView;
@property(nonatomic, readonly) MCPlayerGeneralHeader *topView;
@property(nonatomic, readonly) MCPlayerGeneralFooter *bottomView;


@property(nonatomic, copy) MCPlayerNormalViewEventCallBack outEventCallBack;
@property(nonatomic, copy) NSString *(^retryPlayUrl)(void); ///< 获取url尝试重新播放
@property(nonatomic, copy) BOOL (^canShowTerminalCallBack)(void);
@property(nonatomic, assign) BOOL unableSeek;
@property(nonatomic, assign) BOOL isLive;
@property(nonatomic, assign) BOOL notTop;
@property(nonatomic, assign) BOOL onlyFullScreen;

- (void)updatePlayerStyle:(MCPlayerStyleSizeType)styleSizeType;

- (void)updateTitle:(NSString *)title;

- (void)currentTime:(double)time;

- (void)duration:(double)time;

- (void)updateProgress:(float)progress;

- (void)updateBufferProgress:(float)progress;

- (BOOL)isLock;

- (void)updateAction:(__weak MCPlayerKit *)playerKit;

- (void)updatePlayerPicture:(NSString *)url;

/**
 * 横屏幕
 */
- (void)rotate2Landscape;

/**
 * 16 / 9 半屏
 */
- (void)rotate2Portrait;

/**
 * 竖屏全屏
 */
- (void)rotate2PortraitFullScreen;

- (void)reset;
@end
