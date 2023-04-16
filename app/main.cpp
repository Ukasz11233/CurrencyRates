#include <iostream>
#include <project/CurrentRates.h>
#include <project/FixerApiReader.h>
#include <logger/Log.h>


int main() {
    FixerApiReader fixer;
    Log::LOG_DEBUG("test");
    fixer.getCurrentRate();
    return 0;
}
