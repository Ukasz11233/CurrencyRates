//
// Created by ukasz on 30.03.2023.
//

#ifndef CURRENCYRATES_CURRENTRATES_H
#define CURRENCYRATES_CURRENTRATES_H
#include <iostream>
#include <map>
#include <curl/curl.h>
#include <sstream>

class CurrentRates {
public:
    CurrentRates();
    friend std::ostream & operator<<(std::ostream & output, const CurrentRates & currentRates);
    double getCurrentRate(std::string) const;
    std::string toString() const;
    void getCurrentRateFromFixerApi();
private:
    double currentRate;
    std::map<std::string, double> currentValues;
};


#endif //CURRENCYRATES_CURRENTRATES_H
