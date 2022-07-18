
#import <Foundation/Foundation.h>

@interface NSDictionary (STPExtension)
- (NSString *)JSONString;
/**
 *  @brief  将url参数转换成NSDictionary
 *
 *  @param query url参数
 *
 *  @return NSDictionary
 */
+ (NSDictionary *)dictionaryWithURLQuery:(NSString *)query;
/**
 *  @brief  将NSDictionary转换成url 参数字符串
 *
 *  @return url 参数字符串
 */
- (NSString *)URLQueryString;

- (BOOL)hasKey:(NSString *)key;

- (NSString*)stringForKey:(id)key;

- (NSNumber*)numberForKey:(id)key;

- (NSDecimalNumber *)decimalNumberForKey:(id)key;

- (NSArray*)arrayForKey:(id)key;

- (NSDictionary*)dictionaryForKey:(id)key;

- (NSInteger)integerForKey:(id)key;

- (NSUInteger)unsignedIntegerForKey:(id)key;

- (BOOL)boolForKey:(id)key;

- (int16_t)int16ForKey:(id)key;

- (int32_t)int32ForKey:(id)key;

- (int64_t)int64ForKey:(id)key;

- (char)charForKey:(id)key;

- (short)shortForKey:(id)key;

- (float)floatForKey:(id)key;

- (double)doubleForKey:(id)key;

- (long long)longLongForKey:(id)key;

- (unsigned long long)unsignedLongLongForKey:(id)key;

- (NSDate *)dateForKey:(id)key dateFormat:(NSString *)dateFormat;

@end

#pragma --mark NSMutableDictionary setter

@interface NSMutableDictionary(SafeAccess)

-(void)setObj:(id)i forKey:(NSString*)key;

-(void)setString:(NSString*)i forKey:(NSString*)key;

-(void)setBool:(BOOL)i forKey:(NSString*)key;

-(void)setInt:(int)i forKey:(NSString*)key;

-(void)setInteger:(NSInteger)i forKey:(NSString*)key;

-(void)setUnsignedInteger:(NSUInteger)i forKey:(NSString*)key;

@end
