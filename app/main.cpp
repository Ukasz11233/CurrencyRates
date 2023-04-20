#include <iostream>
#include <project/CurrentRates.h>
#include <chrono>
#include <thread>
#include <logger/Log.h>

int main() {
    CurrentRates currentRates;
    while(true)
    {
        system("clear");
        Log::LOG_INFO(currentRates.toString());
        std::this_thread::sleep_for(static_cast<std::chrono::seconds>(1));

    }


    return 0;
}
