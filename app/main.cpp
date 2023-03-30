#include <iostream>
#include <project/CurrentRates.h>

int main() {
    CurrentRates currentRates(20.4);
    currentRates.getCurrentRateFromFixerApi();
    return 0;
}
