//
//  KDConstants.h
//  KoraAnalyticsSDK
//
//  Created by 杨志 on 2020/11/11.
//  Copyright © 2020 杨志. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark - typedef
/**
 * @abstract
 * Debug 模式，用于检验数据导入是否正确。该模式下，事件会逐条实时发送到 KoraAnalytics，并根据返回值检查
 * 数据导入是否正确。
 *
 * @discussion
 * Debug 模式的具体使用方式，请参考:
 *  http://www.sensorsdata.cn/manual/debug_mode.html
 *
 * Debug模式有三种选项:
 *   KoraAnalyticsDebugOff - 关闭 DEBUG 模式
 *   KoraAnalyticsDebugOnly - 打开 DEBUG 模式，但该模式下发送的数据仅用于调试，不进行数据导入
 *   KoraAnalyticsDebugAndTrack - 打开 DEBUG 模式，并将数据导入到 KoraAnalytics 中
 */
typedef NS_ENUM(NSInteger, KoraAnalyticsDebugMode) {
    KoraAnalyticsDebugOff,
    KoraAnalyticsDebugOnly,
    KoraAnalyticsDebugAndTrack,
};

/**
 * @abstract
 * TrackTimer 接口的时间单位。调用该接口时，传入时间单位，可以设置 event_duration 属性的时间单位。
 *
 * @discuss
 * 时间单位有以下选项：
 *   KoraAnalyticsTimeUnitMilliseconds - 毫秒
 *   KoraAnalyticsTimeUnitSeconds - 秒
 *   KoraAnalyticsTimeUnitMinutes - 分钟
 *   KoraAnalyticsTimeUnitHours - 小时
 */
typedef NS_ENUM(NSInteger, KoraAnalyticsTimeUnit) {
    KoraAnalyticsTimeUnitMilliseconds,
    KoraAnalyticsTimeUnitSeconds,
    KoraAnalyticsTimeUnitMinutes,
    KoraAnalyticsTimeUnitHours
};


/**
 * @abstract
 * AutoTrack 中的事件类型
 *
 * @discussion
 *   KoraAnalyticsEventTypeAppStart - $AppStart
 *   KoraAnalyticsEventTypeAppEnd - $AppEnd
 *   KoraAnalyticsEventTypeAppClick - $AppClick
 *   KoraAnalyticsEventTypeAppViewPage - $AppViewPage
 *   KoraAnalyticsEventTypeAppDismissPage - $AppDismissPage
 */
typedef NS_OPTIONS(NSInteger, KoraAnalyticsAutoTrackEventType) {
    KoraAnalyticsEventTypeNone      = 0,
    KoraAnalyticsEventTypeAppStart      = 1 << 0,
    KoraAnalyticsEventTypeAppEnd        = 1 << 1,
    KoraAnalyticsEventTypeAppClick      = 1 << 2,
    KoraAnalyticsEventTypeAppViewPage   = 1 << 3,
    KoraAnalyticsEventTypeAppDismissPage = 1 << 4,
};

/**
 * @abstract
 * 网络类型
 *
 * @discussion
 *   KoraAnalyticsNetworkTypeNONE - NULL
 *   KoraAnalyticsNetworkType2G - 2G
 *   KoraAnalyticsNetworkType3G - 3G
 *   KoraAnalyticsNetworkType4G - 4G
 *   KoraAnalyticsNetworkTypeWIFI - WIFI
 *   KoraAnalyticsNetworkTypeALL - ALL
 */
typedef NS_OPTIONS(NSInteger, KoraAnalyticsNetworkType) {
    KoraAnalyticsNetworkTypeNONE      = 0,
    KoraAnalyticsNetworkType2G       = 1 << 0,
    KoraAnalyticsNetworkType3G       = 1 << 1,
    KoraAnalyticsNetworkType4G       = 1 << 2,
    KoraAnalyticsNetworkType5G       = 1 << 3,
    KoraAnalyticsNetworkTypeWIFI     = 1 << 4,
    KoraAnalyticsNetworkTypeALL      = 0xFF,
};

