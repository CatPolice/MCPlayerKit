//
//  MCPlayerKit.h
//  litttleplayer
//
//  Created by majiancheng on 2017/3/17.
//  Copyright © 2017年 mjc inc. All rights reserved.
//


#import "MCPlayerConfig.h"

@class MCPlayer;
@class MCPlayerView;


@protocol MCPlayerDelegate <NSObject>

- (void)playLoading;

- (void)playBuffer;

- (void)playStart;

- (void)playPlay;

- (void)playEnd;

- (void)playError;

- (void)updatePlayView;

- (void)currentTime:(double)time;

@end

@interface MCPlayerKit : NSObject {
@public
    MCPlayer *_player;
}

@property(nonatomic, assign) MCPlayerEnvironment playerEnvironment;
@property(nonatomic, assign) MCPlayerCoreType playerCoreType; ///< default IJKPlayer
@property(nonatomic, assign) MCPlayerActionAtItemEnd actionAtItemEnd;
@property(nonatomic, assign) MCPlayerLayerVideoGravity playerLayerVideoGravity;
@property(nonatomic, assign) BOOL notNeedSetProbesize;

- (instancetype)initWithPlayerView:(__weak MCPlayerView *)playerView;

- (void)updatePlayerView:(MCPlayerView *)playerView;

- (void)addDelegate:(id <MCPlayerDelegate>)delegate;

- (void)removeDelegate:(id <MCPlayerDelegate>)delegate;

- (void)playUrls:(nonnull NSArray<NSString *> *)urls;

- (void)playUrls:(nonnull NSArray<NSString *> *)urls isLiveOptions:(BOOL)isLiveOptions;

- (void)preparePlay;

- (void)play;

- (void)pause;

- (void)destory;

- (NSTimeInterval)duration;

- (NSTimeInterval)currentTime;

- (CGFloat)cacheProgress;

- (void)seekSeconds:(CGFloat)seconds;

- (BOOL)isPlaying;

- (CGSize)naturalSize;

- (BOOL)conditionLimit2CannotPlay;

@end
