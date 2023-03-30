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
    CURLcode res;
    curl = curl_easy_init();
    std::cout << "debug" << std::flush;
    std::unique_ptr<std::string> outData(new std::string());
    if(curl)
    {
        std::ifstream fileApiKey("apiKey.txt");
        std::string apiKey;
        std::getline(fileApiKey, apiKey);
        apiKey.insert(0, "apikey: ");

        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.apilayer.com/fixer/convert?to=PLN&from=EUR&amount=1");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 3);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, outData.get());
        struct curl_slist *headers = nullptr;
        headers = curl_slist_append(headers, apiKey.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        res = curl_easy_perform(curl);
        std::cout << "outData: " << outData.get()->c_str() << std::flush;
    }
//    std::cout << res << std::flush;
}