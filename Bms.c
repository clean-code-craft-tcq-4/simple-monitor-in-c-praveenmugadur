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




/****************TEMP*****************************************/
int BatteryTempLowLimit(float temp)
{	
	if ((temp >= MIN_LOWTEMPBREACH) || (temp <= MIN_TEMPNORMAL))
	{
		return E_NOT_OK; 
	}
	else
	{
		return E_OK; 
	}
}

int BatteryTempHighLimit(float temp, char tempUnit)
{
	if ((temp >= MIN_HIGHTEMPWARNING) || (temp <= MIN_HIGHTEMPBREACH))
	{
		return E_NOT_OK; 
	}
	else 
	{
		inttBattConvertTemp(temp, tempUnit);
		return E_NOT_OK; 
	}
	
}

int checkTempOK(float temp, char tempUnit )
{
	int tempStatus = E_OK;
	if((temp >= MIN_LOWTEMPBREACH) && (temp < MIN_HIGHTEMPWARNING))
	{
		tempStatus = BattTempLowLimit(temp);
	}
	else
	{
		tempStatus = BattTempHighLimit(temp, tempUnit);
	}
	return tempStatus;
}

 bool BatteryTempUnit(char cel)
 {
 	if(cel == TEMP_UNIT_CELCIUS)
		return true;
	 else
		return false;
 }

float BatteryConvertTemp(float temp, char tempUnit)
{
	float celcius;
	if((temp > MAX_HIGHTEMPBREACH) && (tempUnit == TEMP_UNIT_FARENHEIT))
	{
		celcius = (temp - 32) * 5 / 9;
	}
	else
	{
		return temp;
	}
}



/****************ChargeRate*****************************************/
int BatteryChargeRateLowLimit(float chargeRate)
{	
	if ((chargeRate >= MIN_LOWCHARGERATEBREACH) || (chargeRate <= MIN_CHARGERATENORMAL))
	{
		return E_NOT_OK; 
	}
	else
	{
		return E_OK; 
	}
}

int BatteryChargeRateHighLimit(float chargeRate)
{
	if ((chargeRate >= MIN_HIGHCHARGERATEWARNING) || (chargeRate <= MIN_HIGHCHARGERATEBREACH))
	{
		return E_NOT_OK; 
	}
	else 
	{
		return E_NOT_OK; 
	}
	
}

int checkchargeRate(float chargeRate )
{
	int chargeRateStatus = E_OK;
	if((chargeRate >= MIN_LOWCHARGERATEBREACH) && (chargeRate < MIN_HIGHCHARGERATEWARNING))
	{
		chargeRateStatus = BatteryChargeRateLowLimit(chargeRate);
	}
	else
	{
		chargeRateStatus = BatteryChargeRateHighLimit(chargeRate);
	}
	return chargeRateStatus;
}




int batteryCheck( float soc, float temp , float chargeRate, char tempUnit )
{	
	float stateOfCharge = checkSocOk(soc);
	float temperature = checkTempOK(temp, tempUnit);
	float chargerate = checkchargeRate(chargeRate);
	return (stateOfCharge && temperature && chargerate);
}


