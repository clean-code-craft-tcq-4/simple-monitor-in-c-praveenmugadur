#include<stdio.h>  
#include "Bms.h"

/****************SOC*****************************************/
int BatterySocLowLimit(float soc)
{	
	if ((soc >= MIN_LOWSOCBREACH) || (soc <= MIN_SOCNORMAL))
	{
		return E_NOT_OK; 
	}
	else
	{
		/*SOC of Battery is in charging state*/
		return E_OK; 
	}
}

int BatterySocHighLimit(float soc)
{
	if ((soc >= MIN_HIGHSOCWARNING) || (soc <= MIN_HIGHSOCBREACH))
	{
		return E_NOT_OK; 
	}
	else 
	{
		return E_NOT_OK; 
	}
	
}

int checkSocOk(float soc )
{
	int socStatus = E_OK;
	if((soc >= MIN_LOWSOCBREACH) && (soc <= MIN_HIGHSOCWARNING))
	{
		socStatus = BatterySocLowLimit(soc);
	}
	else
	{
		socStatus = BatterySocHighLimit(soc);
	}
	return socStatus;
}

int batteryCheck( float soc, float temp , float chargeRate, char tempUnit )
{	
	float stateOfCharge = checkSocOk(soc);
	float temperature = checkTempOK(temp, tempUnit);
	float chargerate = checkchargeRate(chargeRate);
	return (stateOfCharge && temperature && chargerate);
}


