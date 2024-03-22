//
//  STPWordDeviceNetworkApi.h
//  TalkyPen
//
//  Created by roobo on 2022/4/22.
//  Copyright © 2022 aie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "STPWordDeviceModel.h"
//类型，0 public 1 appId 2 user 3 sn，本次用户自定词库设置为2 （二期）
typedef NS_ENUM (NSInteger , STP_oType) {
    STP_oType_public = 0,
    STP_oType_appId = 1,
    STP_oType_user = 2,
    STP_oType_sn = 3,
    STP_oType_unknown = 10000//二期以前默认这个，接口不传值
};

NS_ASSUME_NONNULL_BEGIN

#define dict_list_pageSize 20

@interface STPWordDeviceNetworkApi : NSObject

/// 激活设备
/// @param time 当前秒级时间戳，用于生成signature
/// @param secret 设备token
/// @param deviceId 设备id
/// @param block block
+ (void)createDeviceSessionWithTime:(NSString *)time
                          andSecret:(NSString *)secret
                             andDevice:(NSString *)deviceId
                           Callback:(void (^)(STPWordDeviceSessionModel * _Nullable deviceSessionModel,NSError * _Nullable error))block;

/// 绑定设备
/// @param deviceId 设备id
/// @param deviceAppId appid
/// @param block block
+ (void)bindWordDevice:(NSString *)deviceId
                 andDeviceAppId:(NSString *)deviceAppId
                    andCallback:(void (^)(id _Nullable response,NSError * _Nullable error))block;

/// 上报设备属性
/// @param deviceInfo 设备信息
/// @param clientId 设备id
/// @param timestamp 当前毫秒级时间戳
/// @param block block
+ (void)uploadDeviceInfo:(NSDictionary *)deviceInfo
             andClientId:(NSString *)clientId
                 andTime:(NSString *)timestamp
             andCallback:(void (^)(id _Nullable response,NSError * _Nullable error))block;

+ (void)checkWordDeviceOTAVersionWithDeviceVersion:(NSString *)version
                                        Callback:(void (^)(STPWordDeviceOTAUpdateModel * _Nullable deviceOTAModel,NSError * _Nullable error))block;

/// 获取设备词库设置
/// otype 类型，0 public 1 appId 2 user 3 sn，本次用户自定词库设置为2
/// @param block block
+ (void)getDeviceWordDictWith:(NSInteger)oType andCallback:(void (^)(STPWordDeviceDictDetailModel * _Nullable wordDictModel,NSError * _Nullable error))block;


/// 获取设备词库列表设置 （多词库版本）
/// otype 类型，0 public 1 appId 2 user 3 sn，本次用户自定词库设置为2
/// @param block block
+ (void)getDeviceWordDictListWith:(NSInteger)oType andCallback:(void (^)(NSArray <STPWordDeviceDictDetailModel *> *wordDictList,NSError * _Nullable error))block;

/// 查询词库分类
/// @param pid 父类id，不填返回所有，填0返回一级分类
/// @param dictType 词典类型 （单词机填写 @"small" 小型词库，适用于 卡片机）
/// @param block block
+ (void)getWordDictCategoryWith:(NSInteger)pid
                    andDictType:(NSString *)dictType
                    andCallback:(void (^)(NSArray <STPWordDeviceCategoryDictModel *> *wordDictList,NSError * _Nullable error))block;

/// 查询词库列表
/// @param dictType 词典类型 （单词机填写 @"small" 小型词库，适用于 卡片机）
/// @param categoryId 分类id，查询该分类以及其子分类下的数据
/// @param page 分页，第几页，默认1
/// @param pageSize 分页，每页条数，默认20，最大500
/// @param block block
+ (void)getWordDictListWithDictType:(NSString *)dictType
                  andCategoryId:(NSInteger)categoryId
                        andPage:(NSNumber *)page
                        andPageSize:(NSNumber *)pageSize
                    andCallback:(void (^)(STPWordDeviceDictListModel * _Nullable listModel,NSError * _Nullable error))block;

/// 查询词库列表
/// @param categoryId 分类id，查询该分类以及其子分类下的数据
/// @param ids 词库id
/// @param dictType 词典类型 （单词机填写 @"small" 小型词库，适用于 卡片机）
/// @param oType 类型，public:0,appId:1,user:2,sn:3，(用户自定词库设置为2)
/// @param owner 根据oType填写，如果是用户自定词库设置为具体的userId
/// @param page 分页，第几页，默认1
/// @param pageSize 分页，每页条数，默认20，最大500
/// @param block block
+ (void)getWordDictCategoryWithCategoryId:(NSNumber *)categoryId
                                   andIds:(NSArray *)ids
                              andDictType:(NSString *)dictType
                                 andOType:(NSNumber *)oType
                                 andOwner:(NSString *)owner
                                  andPage:(NSNumber *)page
                              andPageSize:(NSNumber *)pageSize
                              andCallback:(void (^)(STPWordDeviceDictListModel * _Nullable listModel, NSError * _Nullable error))block;

/// 保存词库设置 (单词库版本)
/// @param d_id 词库id
/// @param numPerDay 每天学习的单词数
/// @param hasSentence 是否有例句
/// @param hasExercise 是否有习题
/// @param oType 类型
/// @param block block
+ (void)uploadWordDictSet:(NSInteger)d_id andNumperDay:(NSInteger)numPerDay andHasSentence:(BOOL)hasSentence andHasExercise:(BOOL)hasExercise OType:(STP_oType)oType andCallback:(void (^)(BOOL, NSError * _Nullable))block;

/// 保存词库设置 (多词库版本)
/// @param d_id 词库id
/// @param numPerDay 每天学习的单词数
/// @param hasSentence 是否有例句
/// @param hasExercise 是否有习题
/// @param oType 类型
/// @param clearDictHistory 是否清除前一个词库的学习记录，1是，0否，默认为1
/// @param block block
+ (void)uploadWordDictSet:(NSInteger)d_id
             andNumperDay:(NSInteger)numPerDay
           andHasSentence:(BOOL)hasSentence
           andHasExercise:(BOOL)hasExercise
                    OType:(STP_oType)oType
      andClearDictHistory:(BOOL)clearDictHistory
                  andMode:(NSInteger)mode
              andCallback:(void (^)(BOOL isSuss,NSError * _Nullable error))block;

/// 删除词库设置 （多词库版本）
/// @param ids 词库id列表
/// @param block block
+ (void)deleteDictWith:(NSArray *)ids andCallback:(void (^)(BOOL isSuss,NSError * _Nullable error))block;

/// 设备学习记录上报
/// @param listId 词库ID
/// @param freshArray 新学记录
/// @param reviewArray 复习记录
/// @param block block
+ (void)uploadDeviceStudyRecord:(long)listId andFresh:(NSArray *)freshArray andReview:(NSArray *)reviewArray andBlock:(void (^)(BOOL isSuccess,NSError *_Nullable error))block;

/// 获取词库单词列表
/// @param dictId 词库ID，如不填，则自动获取设备设置的词库
/// @param page 页数，从1开始
/// @param type 类型，0 全部 1 已学 2 未学
/// @param block block
+ (void)getDictWordsWitDictId:(long )dictId
                                         andPage:(NSInteger)page
                                         andType:(NSInteger)type
                                     andCallback:(void (^)(STPWDStudyWordModel * _Nullable studyWordModel,NSError * _Nullable error))block;

/// 此接口主要用于保存自定义词库
/// @param oType 类型，public:0,appId:1,user:2,sn:3，(用户自定词库设置为2)
/// @param wid 词库ID，如果为0，表示新增
/// @param name 词库名称
/// @param status 词库状态，0可用，1 不可用，用户自定词库设置为1
/// @param block block
+ (void)saveCustomWordSetWithOType:(NSInteger)oType andWid:(NSInteger)wid andName:(nonnull NSString *)name andStatus:(NSInteger)status andCallback:(void (^)(STPWordDeviceDictDetailModel * _Nullable wordDeviceDictDetailModel,NSError * _Nullable error))block;


/// 此接口主要用于删除自定义词库
/// @param oType 类型，public:0,appId:1,user:2,sn:3，(用户自定词库设置为2)
/// @param wid 词库ID
/// @param status 词库状态，0可用，1 不可用，用户自定词库设置为1
/// @param block block
+ (void)deleteCustomWordSetWithOType:(NSInteger)oType andWid:(nonnull NSNumber *)wid andStatus:(NSInteger)status andCallback:(void (^)(id response, NSError *error))block;


/// 此接口主要用于查询单词
/// @param content 关键字，后台支持按照空格、换行、分号分隔查询
/// @param wid 词库ID
/// @param page 页数，从1开始
/// @param pageSize 每页条数，默认20，最大100
/// @param block block
+ (void)queryMatchingWordSetWithContent:(nonnull NSString *)content andWid:(nonnull NSNumber *)wid andPage:(NSInteger)page andPageSize:(NSInteger)pageSize andCallback:(void (^)(STPWDStudyWordModel * _Nullable studyWordModel, NSError *error))block;


/// 此接口主要用于打包自定义词库
/// @param oType 类型，public:0,appId:1,user:2,sn:3，(用户自定词库设置为2)
/// @param wid 词库ID
/// @param block block
+ (void)buildCustomWordSetWithOType:(NSInteger)oType andWid:(nonnull NSNumber *)wid andCallback:(void (^)(id response, NSError *error))block;


/// 此接口主要用于从自定义词库中删除单词
/// @param wordArray 单词id列表
/// @param wid 词库ID
/// @param block block
+ (void)deleteWordWithArray:(NSArray *)wordArray andWid:(nonnull NSNumber *)wid andCallback:(void (^)(id response, NSError *error))block;


/// 此接口主要用于添加单词到自定义词库
/// @param wordArray 单词列表 @（
///                           @"id":单词a id,
///                           @"id":单词b id,
///                            ）
/// @param wid 词库ID
/// @param block block
+ (void)addWordWithArray:(NSArray *)wordArray andWid:(nonnull NSNumber *)wid andCallback:(void (^)(id response, NSError *error))block;


/// OCR图片提取文字
/// @param imageData 图片data
/// @param distinct 是否去重，0否 1是
/// @param progressBlock 进度
/// @param resultBlock resultBlock
+ (void)uploadOcrImg:(NSData *)imageData addDistinct:(NSInteger)distinct progressBlock:(void(^)(NSProgress *progress))progressBlock resultBlock:(void (^)(id response, NSError * error))resultBlock;

@end

NS_ASSUME_NONNULL_END
