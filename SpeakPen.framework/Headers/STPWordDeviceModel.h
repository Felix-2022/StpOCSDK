//
//  STPWordDeviceModel.h
//  TalkyPen
//
//  Created by roobo on 2022/4/22.
//  Copyright © 2022 aie. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger,STPWordDeviceDictDetailType) {
    STPWordDeviceDictDetailType_Public = 1,             // 公共
    STPWordDeviceDictDetailType_Custom = 2,             // 自定义
};
NS_ASSUME_NONNULL_BEGIN

@interface STPWordDeviceModel : NSObject

@end


@interface STPWordDeviceSessionModel : NSObject

@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *session;
@property (nonatomic, copy) NSString *clientId;
@property (nonatomic, assign) double expire;    // session的有效截止时间（unix时间戳），设备需要在session结束前，主动获取新的session目前有效期；目前默认是7天内session有效；7天后会更换新的session
@property (nonatomic, assign) NSInteger timeout;    // session剩余有效时间=expire-当前时间

@end

@interface STPWordDeviceOTAUpdateDetaModel : NSObject

@property (nonatomic, copy) NSArray *urls;
@property (nonatomic, assign) NSInteger fileSize;    //
@property (nonatomic, copy) NSString *fileMd5;

@end

@interface STPWordDeviceOTAUpdateModel : NSObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *verName;
@property (nonatomic, copy) NSString *fileMd5;
@property (nonatomic, copy) NSArray *urls;
@property (nonatomic, assign) NSInteger verCode;    //
@property (nonatomic, assign) NSInteger fileSize;    //
@property (nonatomic, strong) STPWordDeviceOTAUpdateDetaModel *deta;
@property (nonatomic, copy) NSString *features;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *custom;
@end

@interface STPWordDeviceCategoryDictModel : NSObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, assign) NSInteger c_id;
@property (nonatomic, assign) NSInteger pid; // 分类父id

@end


/// 设备词库
@interface STPWordDeviceDictDetailContentModel : NSObject

@property (nonatomic, copy) NSString *url; // 词库下载地址
@property (nonatomic, copy) NSString *file_md5; // 词库版本和签名
@property (nonatomic, assign) long size;     // 词库大小，单位字节
@property (nonatomic, copy) NSString *pkg_uuid; //
@property (nonatomic, assign) long pkg_version;     // 词库版本

@end

/// 设备词库
@interface STPWordDeviceDictDetailModel : NSObject

@property (nonatomic, strong) NSNumber *w_id;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *cover;
@property (nonatomic, copy) NSString *sync_at;
@property (nonatomic, assign) NSInteger build_status; // 打包状态，0未打包，1打包中，2打包成功，3打包失败（二期）
@property (nonatomic, copy) NSString *build_end_at;   // 最后打包时间（二期）
@property (nonatomic, copy) NSString *updated_at;   // 词库更新时间（修改基本信息、添加单词、删除单词等）
@property (nonatomic, copy) NSString *d_description;
@property (nonatomic, assign) NSInteger word_count;      // 单词数
@property (nonatomic, assign) NSInteger num_per_day;     // 每天学习的单词数
@property (nonatomic, assign) NSInteger has_sentence;     // 是否需要例句，1是 0 否
@property (nonatomic, assign) NSInteger has_exercise;     // 是否需要习题，1是 0 否
@property (nonatomic, assign) NSInteger study_word_count;     // 已学单词数
@property (nonatomic, strong) STPWordDeviceDictDetailContentModel *content;
@property (nonatomic, assign) STPWordDeviceDictDetailType dictType;      

@end

@interface STPWordDevicePublicPageModel : NSObject

@property (nonatomic, assign) NSInteger page;
@property (nonatomic, assign) NSInteger pageSize;
@property (nonatomic, assign) NSInteger total;

@end

@interface STPWordDeviceDictListModel : NSObject

@property (nonatomic, strong) STPWordDevicePublicPageModel *pager;
@property (nonatomic, copy) NSArray <STPWordDeviceDictDetailModel *>*list;

@end

///
@interface STPWordDeviceWordDetailModel : NSObject

@property (nonatomic, assign) NSInteger w_id;
@property (nonatomic, assign) NSInteger listId;      // 当天
@property (nonatomic, assign) NSInteger score;     // 复习词汇
@property (nonatomic, assign) NSInteger star;     //
@property (nonatomic, copy) NSString *word;
@property (nonatomic, copy) NSString *audio;
@property (nonatomic, copy) NSArray *means;
@property (nonatomic, copy) NSString *soundmark;

@end

@interface STPWordDeviceWordListModel : NSObject

@property (nonatomic, strong) STPWordDevicePublicPageModel *pager;
@property (nonatomic, copy) NSArray <STPWordDeviceWordDetailModel *>*list;
@property (nonatomic, assign) NSInteger wordListId;
@property (nonatomic, copy) NSString *wordListName;

@end

/// 发音 音标信息
@interface STPWDStudyWordPhENModel : NSObject

@property (nonatomic, copy) NSString *soundmark;

@end

@interface STPWDStudyWordDetailModel : NSObject

@property (nonatomic, assign) NSInteger w_id;
@property (nonatomic, assign) NSInteger listId;      // 当天
@property (nonatomic, assign) NSInteger score;     // 复习词汇
@property (nonatomic, assign) NSInteger star;     //
@property (nonatomic, copy) NSString *word;
@property (nonatomic, copy) NSString *audio;
@property (nonatomic, copy) NSArray *means;
@property (nonatomic, strong) STPWDStudyWordPhENModel *phModel; // 音标信息
@property (nonatomic, copy) NSString *soundmark;
@property (nonatomic, assign) NSInteger style;//本地cell状态，非后台字段 （自定义词库使用0未选中1选中 ）
@end


@interface STPWDStudyWordModel : NSObject

@property (nonatomic, strong) STPWordDevicePublicPageModel *pager;
@property (nonatomic, copy) NSArray <STPWDStudyWordDetailModel *>*list;
@property (nonatomic, copy) NSString *date;

@end

/// 单词机设备详情
@interface STPWDDeviceDetailModel : NSObject<NSCoding,NSCopying>
@property (nonatomic,strong) NSString *deviceID;//  设备ID
@property (nonatomic,assign) float battery;//设备当前电量
@property (nonatomic,assign) BOOL manager;// YES管理员 NO普通成员
@property (nonatomic,strong) NSString *name;//设备的名称
@property (nonatomic,assign) BOOL online;//是否连接网络
@property (nonatomic,assign) BOOL power;//是否在充电中
@property (nonatomic,assign) BOOL power_supply;// 是否连接电源
@property (nonatomic,strong) NSString *device_type;// 设备类型
@property (nonatomic,assign) NSInteger volume;// 设备类型
@property (nonatomic,strong) NSString *appId;
@property (nonatomic,strong) NSString *wifissid;
@property (nonatomic,strong) NSString *version;
@end

NS_ASSUME_NONNULL_END
