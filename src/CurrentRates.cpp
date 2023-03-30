//
// Created by ukasz on 30.03.2023.
//

#include <fstream>
#include "project/CurrentRates.h"

std::ostream & operator<<(std::ostream & output, const CurrentRates & currentRates)
{
    output << "Current rate: " <<  currentRates.currentRate;
    return output;
}

double CurrentRates::getCurrentRate() const
{
    return currentRate;
}

void CurrentRates::getCurrentRateFromFixerApi()
{
    CURL * curl;
    CURLcode res;
    curl = curl_easy_init();
    std::cout << "debug" << std::flush;
    if(curl)
    {
        std::ifstream fileApiKey("apiKey.txt");
        std::string apiKey;
        std::getline(fileApiKey, apiKey);
        apiKey.insert(0, "apikey: ");
        std::cout << apiKey << std::flush;
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.apilayer.com/fixer/convert?to=PLN&from=EUR&amount=1");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 3);
        struct curl_slist *headers = nullptr;
        headers = curl_slist_append(headers, apiKey.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        std::cout << "debug" << std::flush;

        res = curl_easy_perform(curl);
        std::cout << "debug\n" << std::flush;

                std::ostringstream res_output;
        res_output << res;
        std::ofstream currency_out("output.txt");
        currency_out << res_output.str();
        std::cout << "\n" << res_output.str() << std::flush;
    }
    std::cout << res << std::flush;
}