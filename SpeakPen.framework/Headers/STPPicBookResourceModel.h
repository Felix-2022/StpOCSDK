 

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 绘本或者点读包资源（添加到设备之前）
@interface STPPicBookResourceModel : NSObject

@property(nonatomic,assign) NSInteger rID;//资源ID
@property(nonatomic,strong) NSString *name;
@property(nonatomic,strong) NSString *cover;
@property(nonatomic,strong) NSString *author;
@property(nonatomic,strong) NSString *mid;// 点读包id
@property(nonatomic,assign) NSInteger size;
@property(nonatomic,assign) NSInteger status;// 添加状态 0未添加 1已添加
@property(nonatomic,assign) NSInteger downloadable;//是否可以下载 0否 1是
@property(nonatomic,assign) NSInteger createdAt;//
@property(nonatomic,assign) NSInteger updatedAt;//

@end

@interface STPPicBookResourceList : NSObject

@property(nonatomic,assign) NSInteger total;// 分类的总数量
@property(nonatomic,strong) NSArray<STPPicBookResourceModel*> *lists;// 资源分类列表

@end


/// 绘本或点读包详情（已经添加到设备）
@interface STPPicBookDetailModel : NSObject

@property(nonatomic,assign) NSInteger rID; //资源ID
@property(nonatomic,assign) NSInteger dbId;
@property(nonatomic,strong) NSString *name;
@property(nonatomic,strong) NSString *cover;
@property(nonatomic,strong) NSString *readGuideHtml;
@property(nonatomic,strong) NSString *desc;
@property(nonatomic,strong) NSString *author;
@property(nonatomic,strong) NSString *mid; // 点读包id
@property(nonatomic,assign) NSInteger size; //书籍大小 字节
@property(nonatomic,assign) NSInteger status; // 添加状态 0未添加 1已添加
@property(nonatomic,assign) NSInteger progress; // 下载进度 0-100
@property(nonatomic,assign) NSInteger downloadStatus; //下载状态 0等待下载 1下载中 2下载完成 3下载失败
@property(nonatomic,assign) NSInteger downLoadStatus; 
@property(nonatomic,assign) NSInteger createdAt;
@property(nonatomic,assign) NSInteger updatedAt;
@property(nonatomic,assign) NSInteger downloadable;
@property(nonatomic,strong) NSArray *buyUrls;

@end

/// 绘本详情列表
@interface STPPicBookDetailList : NSObject

@property(nonatomic,assign) NSInteger total; // 分类的总数量
@property(nonatomic,strong) NSArray<STPPicBookDetailModel*> *lists; // 绘本列表

@end

/// 绘本详情列表
@interface STPSdcardInfo : NSObject

@property(nonatomic,assign) NSInteger sdMemUsed; //单位 MB， 已用空间
@property(nonatomic,assign) NSInteger sdMemTotal; //单位 MB， 总空间


@end

NS_ASSUME_NONNULL_END
