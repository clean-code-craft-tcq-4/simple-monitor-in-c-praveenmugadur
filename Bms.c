#include<stdio.h>  
#include "Bms.h"

int batteryCheck(float value, float min, float max)
{
    if (value < min || value > max)
    {
        return Check_NOT_OK;
    }

    return Check_OK;
}

int checkTemp(float temperature)
{
   int val = batteryCheck(temperature, 0, 45);
    if(val == Check_NOT_OK){
         printf("Temperature out of range!\n");
        return Check_NOT_OK;
    }
    else {
         return Check_OK;
    }      
}

int checkSoc(float soc)
{
   int val = batteryCheck(soc, 20, 80);
    if(val == Check_NOT_OK){
         printf("State of Charge out of range!\n");
        return Check_NOT_OK;
    }
    else {
         return Check_OK;
    }      
}

int checkchargeRate(float chargeRate)
{
   int val = batteryCheck(chargeRate, 0, 0.8);
    if(val == Check_NOT_OK){
         printf("State of Charge out of range!\n");
        return Check_NOT_OK;
    }
    else {
         return Check_OK;
    }      
}
