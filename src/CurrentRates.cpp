//
// Created by ukasz on 30.03.2023.
//
#include <logger/Log.h>
#include "project/CurrentRates.h"
#include "../currencies.h"
CurrentRates::CurrentRates()
{
    for(auto currency : {CURRENCIES})
    {
        currentValues.insert({currency, 0});
    }
}

std::ostream & operator<<(std::ostream & output, const CurrentRates & currentRates)
{
    output << "Current rate: " <<  currentRates.currentRate;
    return output;
}

double CurrentRates::getCurrentRate(std::string currency) const
{
    auto pos = currentValues.find(currency);
    if(pos == currentValues.end())
    {
        return -1;
    }
    return pos -> second;
}

std::string CurrentRates::toString() const
{
    std::string output{"Current currency values\n"};
    for(auto currency : {CURRENCIES})
    {
        output.append(currency);
        output.append(": ");
        output.append(std::to_string(this -> getCurrentRate(currency)));
        output.append("\n");
    }
    return output;
}
