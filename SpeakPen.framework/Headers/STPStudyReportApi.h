 

#import <Foundation/Foundation.h>
#import "STPStudyReportModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface STPStudyReportApi : NSObject

/// 获取当天学习数据
/// @param type 候选值对应的字符串(获取跟读数据 传 @"follow-reading")
/// 1: 点读数量(point-reading)
/// 2：绘本阅读量 (pic-book)
/// 3：学习时长(duration)
/// 4：跟读次数 (follow-reading)
/// @param block block
+ (void)getTodayFollowReadingListWithType:(NSString *)type andCallback:(nullable void(^)(STPFollowReadResultModel *_Nullable detailModel,NSError* _Nullable error))block;

/// 获取前几天学习数据
/// @param type type
/// 1: 点读数量(point-reading)
/// 2：绘本阅读量 (pic-book)
/// 3：学习时长(duration)
/// 4：跟读次数 (follow-reading)
/// @param dayCount dayCount (需要获取过去几天的数据就传对应数字，例如获取过去7天的数据，传 7)
/// @param block block
+ (void)getPassdayFollowReadingListWithType:(NSString *)type
                              andPassDay:(NSInteger)dayCount
                              andCallback:(nullable void(^)(STPFollowReadResultModel *_Nullable detailModel,NSError* _Nullable error))block;

/// 获取当天阅读详情
/// @param block block
+ (void)getTodayReadBookListCallback:(nullable void(^)(STPFollowReadResultModel *_Nullable detailModel,NSError* _Nullable error))block;

/// 获取前几天阅读详情
/// @param dayCount dayCount
/// @param block block
+ (void)getPassdayReadBookListWithPassDay:(NSInteger)dayCount
                              andCallback:(nullable void(^)(STPFollowReadResultModel *_Nullable detailModel,NSError* _Nullable error))block;

/// 获取前几天历史趋势数据详情
/// @param type (数据类型 例如：获取点读次数 传@"point-reading")
/// 1: 点读数量(point-reading)
/// 2：学习时长(duration)
/// @param dayCount dayCount
/// @param block block
+ (void)getPassdayTrendListWithType:(NSString *)type
                              andPassDay:(NSInteger)dayCount
                              andCallback:(nullable void(^)(STPTrendListModel *_Nullable detailModel,NSError* _Nullable error))block;

/// 大屏同步开关接口
/// @param enable YES开 NO关
+ (void)handleSyncSwitch:(BOOL)enable
                   block:(nullable void (^)(BOOL isSuss,NSError* _Nullable error))block;

/// 发送大屏同步心跳接口
+ (void)sendSyncHeartbeatWithBlock:(nullable void (^)(BOOL isSuss,NSError* _Nullable error))block;

@end

NS_ASSUME_NONNULL_END
