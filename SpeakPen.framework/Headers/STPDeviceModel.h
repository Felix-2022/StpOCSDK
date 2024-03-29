 

#import <Foundation/Foundation.h>
@class STPBabyModel;
@class STPPlayInfoModel;
NS_ASSUME_NONNULL_BEGIN
@interface STPDeviceUser : NSObject<NSCoding>
@property (nonatomic,strong) NSString *userID;//用户的userID
@property (nonatomic,strong) NSString *headimg;// 用户头像
@property (nonatomic,strong) NSString *name;//用户名称
@property (nonatomic,assign) BOOL manager;//YES管理员 NO普通成员
@end

@interface STPBindInfo : NSObject<NSCoding> //修改网络或者绑定设备时的结果
@property (nonatomic,strong) NSString *appId; //
@property (nonatomic,strong) NSString *deviceID; // 设备ID
@property (nonatomic,strong) NSString * result; //联网结果（success-成功；failure-失败）注意success 只代表网络连接成功 并不代表当前绑定设备成功
@property (nonatomic,assign) BOOL isFirstBinded; //是否第一次绑定
@property (nonatomic,assign) BOOL isBinded;// 1 代表绑定成功 0 失败
@property (nonatomic,strong) NSString * bindtel; //当前设备已经被绑定时回返回管理员的手机号码
@end

@interface STPDeviceModel : NSObject<NSCoding>
@property (nonatomic,strong) NSString *deviceID;//  设备ID
@property (nonatomic,assign) float battery;//设备当前电量
@property (nonatomic,assign) BOOL manager;// YES管理员 NO普通成员
@property (nonatomic,strong) NSString *name;//设备的名称
@property (nonatomic,assign) BOOL online;//是否连接网络
@property (nonatomic,assign) BOOL power;//是否在充电中
@property (nonatomic,assign) BOOL power_supply;// 是否连接电源
@property (nonatomic,strong) NSString *device_type;// 设备类型
@property (nonatomic,assign) NSInteger volume;
@property (nonatomic,strong) NSString *appId;
@property (nonatomic,strong) NSString *wifissid;
@property (nonatomic,strong) NSString *version;//设备固件版本
@end

@interface STPHardwareModel : NSObject<NSCoding>
@property(nonatomic,strong) NSString *model;// 设备类型
@property(nonatomic,strong) NSString *wifiName;// 连接的wifi名称
@property(nonatomic,strong) NSString *SN;//设备sn
@property(nonatomic,strong) NSString *IP;// 网络ip
@property(nonatomic,strong) NSString *MAC;//硬件mac
@end

NS_ASSUME_NONNULL_END
