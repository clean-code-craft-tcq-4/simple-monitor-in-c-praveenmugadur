#include "TestBatteryStatus.h"

int BatteryTestIsOk(float Soc, float Temp , float ChargeRate, char TempUnit)
{	
	int val = batteryCheckOK(Soc,Temp,ChargeRate,TempUnit);
	return val;
}
int BatteryTestIsNotOk(float Soc, float Temp , float ChargeRate, char TempUnit)
{	
	int val = batteryCheckNotOK(Soc,Temp,ChargeRate,TempUnit);
	return val;
}

void BatteryStatusTest(void)
{
	assert(BatteryTestIsNotOk(88,-1,1.0,'N')); 
	assert(BatteryTestIsNotOk(88,50,0.9,'C')); 
	assert(BatteryTestIsOk(32,39,0.7,'C'));
	assert(BatteryTestIsOk(42,30,0.6,'C'));
	assert(BatteryTestIsOk(42,283,0.6,'F'));
}
