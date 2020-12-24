//
//  KAConfigOptions.h
//  KoraAnalyticsSDK
//
//  Created by 杨志 on 2020/11/13.
//  Copyright © 2020 杨志. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AIKAnalyticsSDK/KAConstants.h>

@class KASecretKey;

NS_ASSUME_NONNULL_BEGIN

@interface KAConfigOptions : NSObject

/**
 指定初始化方法，设置 serverURL
 @param appID 应用id
 @return 配置对象
 */
- (instancetype)initWithAppID:(nonnull NSString *)appID launchOptions:(nullable NSDictionary *)launchOptions NS_DESIGNATED_INITIALIZER;

/// 禁用 init 初始化
- (instancetype)init NS_UNAVAILABLE;

/// 禁用 new 初始化
+ (instancetype)new NS_UNAVAILABLE;

/**
 * @property
 *
 * @abstract
 * 打开 SDK 自动追踪,默认只追踪 App 启动 / 关闭、进入页面、元素点击
 *
 * @discussion
 * 该功能自动追踪 App 的一些行为，例如App 启动 / 关闭、进入页面 等等
 * 该功能默认关闭
 */
@property (nonatomic) KoraAnalyticsAutoTrackEventType autoTrackEventType;

/// 是否自动收集 App Crash 日志，该功能默认是关闭的
@property (nonatomic) BOOL enableTrackAppCrash;

/**
 * @property
 *
 * @abstract
 * 两次数据发送的最小时间间隔，单位秒
 *
 * @discussion
 * 默认值为 15 秒， 在每次调用 track 接口的时候，
 * 都会检查如下条件，以判断是否向服务器上传数据:
 * 1. 是否 WIFI/3G/4G/5G 网络
 * 2. 是否满足以下数据发送条件之一:
 *   1) 与上次发送的时间间隔是否大于 flushInterval
 *   2) 本地缓存日志数目是否达到 flushBulkSize
 * 如果满足这两个条件之一，则向服务器发送一次数据；如果都不满足，则把数据加入到队列中，等待下次检查时把整个队列的内容一并发送。
 * 为了避免占用过多存储，最多只缓存10000条数据。
 */
@property (nonatomic) NSInteger flushInterval;

/**
 * @property
 *
 * @abstract
 * 本地缓存的最大事件数目，当累积日志量达到阈值时发送数据
 *
 * @discussion
 * 默认值为 100，在每次调用 track 接口的时候，都会检查如下条件，以判断是否向服务器上传数据:
 * 1. 是否 WIFI/3G/4G/5G 网络
 * 2. 是否满足以下数据发送条件之一:
 *   1) 与上次发送的时间间隔是否大于 flushInterval
 *   2) 本地缓存日志数目是否达到 flushBulkSize
 * 如果同时满足这两个条件，则向服务器发送一次数据；如果不满足，则把数据加入到队列中，等待下次检查时把整个队列的内容一并发送。
 * 为了避免占用过多存储，最多只缓存 10000 条数据。
 */
@property (nonatomic) NSInteger flushBulkSize;

/// 设置本地缓存最多事件条数，默认为 10000 条事件
@property (nonatomic) NSInteger maxCacheSize;

/// 开启 log 打印
@property (nonatomic, assign) BOOL enableLog;

/// 是否开启 WKWebView 的 H5 打通功能，该功能默认是关闭的
@property (nonatomic) BOOL enableJavaScriptBridge;

/// 开启点击图
@property (nonatomic, assign) BOOL enableHeatMap;

/// 开启可视化全埋点
@property (nonatomic, assign) BOOL enableVisualizedAutoTrack;
#pragma mark - 请求远程配置策略
/// 请求远程配置地址，默认从 serverURL 解析
@property (nonatomic, copy) NSString *remoteConfigURL;

/// 禁用随机时间请求远程配置
@property (nonatomic, assign) BOOL disableRandomTimeRequestRemoteConfig;

/// 最小间隔时长，单位：小时，默认 24
@property (nonatomic, assign) NSInteger minRequestHourInterval;

/// 最大间隔时长，单位：小时，默认 48
@property (nonatomic, assign) NSInteger maxRequestHourInterval;

/// DeepLink 中解析出来的参数是否需要保存到本地
@property (nonatomic, assign) BOOL enableSaveDeepLinkInfo;

/// DeepLink 中用户自定义来源渠道属性 key 值，可传多个。
@property (nonatomic, copy) NSArray<NSString *> *sourceChannels;

/// 是否在手动埋点事件中自动添加渠道匹配信息
@property (nonatomic, assign) BOOL enableAutoAddChannelCallbackEvent;

/// 当 App 进入后台时，是否执行 flush 将数据发送到 SensrosAnalytics，默认为 YES
@property (nonatomic, assign) BOOL flushBeforeEnterBackground;

/// 是否开启加密
@property (nonatomic, assign) BOOL enableEncrypt;

/// 存储公钥的回调
@property (nonatomic, copy) void (^saveSecretKey)(KASecretKey * _Nonnull secretKey);

/// 获取公钥的回调
@property (nonatomic, copy) KASecretKey * _Nonnull (^loadSecretKey)(void);

/// 是否开启多渠道匹配，开启后调用 profile_set,不开启则调用 profile_set_once
@property (nonatomic, assign) BOOL enableMultipleChannelMatch;

@end

/// RSA 公钥秘钥信息
@interface KASecretKey : NSObject <NSCoding>

/// 秘钥版本
@property(nonatomic, assign) NSInteger version;

/// 秘钥值
@property(nonatomic, copy) NSString *key;


@end

NS_ASSUME_NONNULL_END
