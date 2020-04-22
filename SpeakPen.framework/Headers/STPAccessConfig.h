 

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, STPEnv) {
    Env_Online = 0,// 发布环境
    Env_Test,// 测试环境
};


#define STPAccessConfiger [STPAccessConfig defaultConfig]
/**
  stp sdk 全局配置文件
 */
@interface STPAccessConfig : NSObject


/**
 开发环境   分为开发和发布环境
 */
@property(nonatomic,assign) STPEnv developEnv;

/**
   登录用户的id
 */
@property(nonatomic,strong,nonnull) NSString *userID;

/**
   登录用户的accessToken
 */
@property(nonatomic,strong,nonnull) NSString *accessToken;

/**
  当前连接的设备ID 当切换控制设备时 需要更改currDeviceID值
 */
@property(nonatomic,strong,nonnull) NSString *currDeviceID;


/**
 获取配置类
 */
+ (instancetype)defaultConfig;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new  NS_UNAVAILABLE;

/**
 清空资源配置文件
 */
+(void)clearLoginUserData;

@end

NS_ASSUME_NONNULL_END
