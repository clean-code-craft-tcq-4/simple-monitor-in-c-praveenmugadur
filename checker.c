#include <stdio.h>
#include<stdbool.h>  
#include <assert.h>
#include "Bms.h"

int batteryIsOk(float temperature, float soc, float chargeRate) {

  bool tempVal = checkTemp(temperature);
  bool socVal = checkSoc(soc);
  bool chargeRateVal = checkchargeRate(chargeRate);
  
  return (tempVal && socVal && chargeRateVal);
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
