//
//  KoraAnalyticsSDK+Track.h
//  KoraSDK
//
//  Created by 杨志 on 2020/11/6.
//  Copyright © 2020 杨志. All rights reserved.
//

#import <KoraSDK/KoraSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface KoraAnalyticsSDK (Track)

/**
 触发$AppClick事件
 @param view 触发事件的控件
 @param properties 自定义属性
 */
- (void)trackAppClickWithView:(UIView *)view
                   properties:(nullable NSDictionary<NSString *, id> *)properties;

/**
 支持UITableView触发AppClick事件
 @param tableView 触发事件的UITableView视图
 @param indexPath 在UITableView中点击的位置
 @param properties 自定义事件属性
 */
- (void)trackAppClickWithTableView:(UITableView *)tableView
           didSelectRowAtIndexPath:(NSIndexPath *)indexPath
                        properties:(nullable NSDictionary<NSString *, id> *)properties;

/**
 支持UICollcetionView触发AppClick事件
 @param collectionView 触发事件的UITableView视图
 @param indexPath 在UITableView中点击的位置
 @param properties 自定义事件属性
 */
- (void)trackAppClickWithCollectionView:(UICollectionView *)collectionView
                didSelectRowAtIndexPath:(NSIndexPath *)indexPath
                             properties:(nullable NSDictionary<NSString *, id> *)properties;

@end

NS_ASSUME_NONNULL_END
