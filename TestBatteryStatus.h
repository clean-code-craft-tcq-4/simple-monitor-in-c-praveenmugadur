#ifndef TEST_BMSSTATUS_H
#define TEST_BMSSTATUS_H

#include <assert.h>
#include "Bms.h"

extern int BatteryTestIsOk(float Soc, float Temp , float ChargeRate, char TempUnit);
extern int BatteryTestIsNotOk(float Soc, float Temp , float ChargeRate, char TempUnit);
extern void BatteryStatusTest(void);


#endif
