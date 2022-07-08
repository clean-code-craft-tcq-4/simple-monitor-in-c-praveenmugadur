#include <stdio.h> 
#include <assert.h>
#include "Bms.h"

int batteryIsOk(float temperature, float soc, float chargeRate) {

  int tempVal = checkTemp(temperature);
  int socVal = checkSoc(soc);
  int chargeRateVal = checkchargeRate(chargeRate);
  
  return (tempVal && socVal && chargeRateVal);
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
