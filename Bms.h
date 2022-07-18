#ifndef BMS_H
#define BMS_H
#include <stdbool.h>
#define MAX_CAPACITY_BATTERY 25


#define MIN_LOWSOCBREACH          0
#define MIN_LOWSOCWARNING        20
#define MIN_SOCNORMAL		         24
#define MIN_HIGHSOCWARNING 	     75
#define MIN_HIGHSOCBREACH        80
#define MAX_HIGHOCBREACH         100

#define MIN_LOWTEMPBREACH        0
#define MIN_LOWTEMPWARNING       5
#define MIN_TEMPNORMAL           10
#define MIN_HIGHTEMPWARNING      40
#define MIN_HIGHTEMPBREACH       45
#define MAX_HIGHTEMPBREACH       80

#define MIN_LOWCHARGERATEBREACH   0
#define MIN_LOWCHARGERATEWARNING  0.2
#define MIN_CHARGERATENORMAL      0.3
#define MIN_HIGHCHARGERATEWARNING 0.7
#define MIN_HIGHCHARGERATEBREACH  0.8
#define MAX_HIGHCHARGERATEBREACH  1.0

#define TEMP_UNIT_CELCIUS         'C'
#define TEMP_UNIT_FARENHEIT       'F'

#define Check_OK                       0
#define Check_NOT_OK                   1



extern int BattSocLowLimit(float soc);
extern int BattSocHighLimit(float soc);
extern int BatterySocIsOk(float soc );
extern int BattTempLowLimit(float temp);
extern int BattTempHighLimit(float temp , char tempUnit);
extern int BatteryTempIsOk(float temp , char tempUnit );
extern int BattChargeRateLowLimit(float chargeRate);
extern int BattChargeRateHighLimit(float chargeRate);
extern int tBatteryChargeRateIsOk(float chargeRate );
extern bool BattTempUnit(char cel);
extern float BattConvertTemp(float temp, char tempUnit);

extern int batteryIsOk( float soc, float temp , float chargeRate, char tempUnit);
extern int batteryIsNotOk( float soc, float temp , float chargeRate,char tempUnit);



