//
// Created by ukasz on 30.03.2023.
//

#ifndef CURRENCYRATES_CURRENTRATES_H
#define CURRENCYRATES_CURRENTRATES_H
#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <sstream>

class CurrentRates {
public:
    CurrentRates(double _currentRate) : currentRate(_currentRate) {};
    friend std::ostream & operator<<(std::ostream & output, const CurrentRates & currentRates);
    double getCurrentRate() const;

    void getCurrentRateFromFixerApi();
private:
    double currentRate;
};


#endif //CURRENCYRATES_CURRENTRATES_H
