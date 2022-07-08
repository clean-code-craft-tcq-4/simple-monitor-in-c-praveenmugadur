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
