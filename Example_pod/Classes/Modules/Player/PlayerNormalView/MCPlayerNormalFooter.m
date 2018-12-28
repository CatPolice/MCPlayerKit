//
// Created by majiancheng on 2018/12/28.
// Copyright (c) 2018 majiancheng. All rights reserved.
//

#import "MCPlayerNormalFooter.h"

#import <MCStyleDef.h>

#import "PlayerProgress.h"

@interface MCPlayerNormalFooter ()

@property(nonatomic, strong) UIButton *playBtn;
@property(nonatomic, strong) UILabel *durationLabel;
@property(nonatomic, strong) UILabel *currentLabel;
@property(nonatomic, strong) PlayerProgress *playerProgress;
@property(nonatomic, strong) UIButton *screenBtn;

@end

@implementation MCPlayerNormalFooter

- (instancetype)init {
    self = [super init];
    if (self) {
        [self createViews];
        [self addLayout];
    }
    return self;
}

- (void)createViews {
    [self addSubview:self.playBtn];
    [self addSubview:self.currentLabel];
    [self addSubview:self.playerProgress];
    [self addSubview:self.screenBtn];
}

- (void)addLayout {
    if (CGRectIsEmpty(self.frame)) return;

    CGFloat w = CGRectGetHeight(self.frame) - 2 * [MCStyle contentInsetII].top;
    self.playBtn.frame = CGRectMake([MCStyle contentInsetII].left, [MCStyle contentInsetII].top, w, w);
    self.screenBtn.frame = CGRectMake(CGRectGetWidth(self.frame) - w - [MCStyle contentInsetII].right, [MCStyle contentInsetII].top, w, w);
    [self refreshTimeFrame];
}

- (void)refreshTimeFrame {
    if (CGRectIsEmpty(self.frame)) return;
    CGSize durationSize = [self.durationLabel sizeThatFits:CGSizeMake(CGRectGetWidth(self.frame) * .5f, self.durationLabel.font.lineHeight)];
    self.durationLabel.frame = CGRectMake(CGRectGetMinX(self.screenBtn.frame) - durationSize.width - [MCStyle contentInsetII].right,
            (CGRectGetHeight(self.frame) - self.durationLabel.font.lineHeight) / 2.0f,
            durationSize.width,
            self.durationLabel.font.lineHeight);

    CGSize currentSize = [self.currentLabel sizeThatFits:CGSizeMake(CGRectGetWidth(self.frame) * .5f, self.currentLabel.font.lineHeight)];
    self.currentLabel.frame = CGRectMake(CGRectGetMaxX(self.playBtn.frame) + [MCStyle contentInsetIII].left,
            (CGRectGetHeight(self.frame) - self.currentLabel.font.lineHeight) / 2.0f,
            currentSize.width,
            self.currentLabel.font.lineHeight);


    self.playerProgress.frame = CGRectMake(CGRectGetMaxX(self.currentLabel.frame) + [MCStyle contentInsetII].left,
            CGRectGetHeight(self.frame) * 0.25,
            CGRectGetMinX(self.durationLabel.frame) - CGRectGetMaxX(self.currentLabel.frame) - [MCStyle contentInsetII].right,
            CGRectGetHeight(self.frame) * 0.5f);
}

- (void)layoutSubviews {
    [super layoutSubviews];
    [self addLayout];
}

#pragma mark - getter

- (UIButton *)playBtn {
    if (!_playBtn) {
        _playBtn = [UIButton new];
        [_playBtn setImage:[MCStyle imageII] forState:UIControlStateNormal];
        [_playBtn setImage:[MCStyle imageII_s] forState:UIControlStateSelected];
    }
    return _playBtn;
}

- (UILabel *)durationLabel {
    if (!_durationLabel) {
        _durationLabel = [UILabel new];
        _durationLabel.font = [MCFont fontV];
        _durationLabel.textColor = [MCColor colorIII];
    }
    return _durationLabel;
}

- (UILabel *)currentLabel {
    if (!_currentLabel) {
        _currentLabel = [UILabel new];
        _currentLabel.font = [MCFont fontV];
        _currentLabel.textColor = [MCColor colorIII];
    }
    return _currentLabel;
}

- (PlayerProgress *)playerProgress {
    if (!_playerProgress) {
        _playerProgress = [PlayerProgress new];
    }
    return _playerProgress;
}

- (UIButton *)screenBtn {
    if (!_screenBtn) {
        _screenBtn = [UIButton new];
        [_screenBtn setImage:[MCStyle imageIII] forState:UIControlStateNormal];
        [_screenBtn setImage:[MCStyle imageIII_s] forState:UIControlStateSelected];
    }
    return _screenBtn;
}

@end