//
// Created by ukasz on 30.03.2023.
//

#include <fstream>
#include <logger/Log.h>
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

std::size_t callback(
        const char* in,
        std::size_t size,
        std::size_t num,
        std::string* out)
{
    const std::size_t totalBytes(size * num);
    out->append(in, totalBytes);
    return totalBytes;
}

void CurrentRates::getCurrentRateFromFixerApi()
{
    CURL * curl;
    curl = curl_easy_init();
    std::unique_ptr<std::string> outData(new std::string());
    if(curl)
    {
        std::ifstream fileApiKey("apiKey.txt");
        std::string apiKey;
        std::getline(fileApiKey, apiKey);
        apiKey.insert(0, "apikey: ");
        Log::LOG_DEBUG(apiKey);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.apilayer.com/fixer/convert?to=pln&from=EUR&amount=1");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "apikey: uqG5HczlbczRvC7T4vQ9tRr3GBwYzA6L");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        Log::LOG_DEBUG(outData.get()->c_str());
    }
    curl_easy_cleanup(curl);
}