#include <iostream>
#include <project/CurrentRates.h>
#include <logger/Log.h>


int main() {
    CurrentRates currentRates(20.4);
    Log::LOG_DEBUG("test");
    currentRates.getCurrentRateFromFixerApi();
    return 0;
}
