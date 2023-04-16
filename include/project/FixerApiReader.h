//
// Created by ukasz on 02.04.2023.
//

#ifndef CURRENCYRATES_FIXERAPIREADER_H
#define CURRENCYRATES_FIXERAPIREADER_H
#include <iostream>
#include <curl/curl.h>
#include <memory>
#include <fstream>
#include <sstream>



class FixerApiReader {
public:
    FixerApiReader() {};
    FixerApiReader(std::string _toCurrency, std::string _fromCurrency, std::string _amount);


    double getCurrentRate()
    {
        readCurrentRate();
        return currentRate;
    }

private:
    void readCurrentRate();
    std::string toCurrency;
    std::string fromCurrency;
    std::string amount;
    std::string apiKey;
    double currentRate;
};


#endif //CURRENCYRATES_FIXERAPIREADER_H
