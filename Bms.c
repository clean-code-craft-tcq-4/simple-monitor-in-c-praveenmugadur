#include<stdio.h>
#include "Bms.h"

int batteryCheck(float value, float min, float max)
{
    if (value < min || value > max)
    {
        return NOT_OK;
    }

    return IS_OK;
}
