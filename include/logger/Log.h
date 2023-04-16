//
// Created by ukasz on 02.04.2023.
//

#ifndef CURRENCYRATES_LOGGER_H
#define CURRENCYRATES_LOGGER_H
#include <iostream>


class Log {
public:
    inline static void LOG_DEBUG(std::string debugMessage)
    {
        std::cout << "\033[1;33m" << debugMessage << "\033[0m" << std::endl;
    }
private:
};

#endif //CURRENCYRATES_LOGGER_H
