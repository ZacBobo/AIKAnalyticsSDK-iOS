//
//  KoraAnalyticsSDK+Timer.h
//  KoraAnalyticsSDK
//
//  Created by 杨志 on 2020/11/9.
//  Copyright © 2020 杨志. All rights reserved.
//

#import <AIKAnalyticsSDK/KoraAnalyticsSDK.h>

NS_ASSUME_NONNULL_BEGIN

static NSString *const KoraAnalyticsEventBeginKey = @"event_begin";
static NSString *const KoraAnalyticsEventDurationKey = @"event_duration";
static NSString *const KoraAnalyticsEventEventIsPauseKey = @"is_pause";

@interface KoraAnalyticsSDK (Timer)

/**
 开始统计事件时长
 调用这个接口时，并不会触发一次事件，只是开始计时

 @param event 事件名
 */
- (void)trackTimerStart:(NSString *)event;

/**
 结束事件时长统计，计算时长
 
 事件发生时长是从调用-trackTimerStart:方法开始的，一直调用到trackTimerEnd:properties:方法结束。
 如果多次调用-trackTimerStart:方法,则从最后一次调用开始计算。
 如果没有调用-trackTimerStart:方法，就直接调用trackTimerEnd:properties:方法，则触发一次普通事件，不带时长属性
 
 @param event 事件名，与开始事件名一一对应
 @param properties 事件属性
 */
- (void)trackTimerEnd:(NSString *)event
           properties:(nullable NSDictionary *)properties;

/**
 暂停统计事件时长
 
 如果该事件未开始，即没有调用-trackTimerStart:方法，则不做任何操作
 
 @param event 事件名
 */
- (void)trackTimerPause:(NSString *)event;

/**
 恢复统计事件时长
 
 如果该事件未暂停，即没有调用-trackTimerPause:方法，则没有影响
 
 @param event 事件名
 */
- (void)trackTimerResume:(NSString *)event;

@end

NS_ASSUME_NONNULL_END
