//
// Created by ukasz on 02.04.2023.
//
#include "project/FixerApiReader.h"
#include "logger/Log.h"
#include <exception>

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

FixerApiReader::FixerApiReader(std::string _toCurrency, std::string _fromCurrency, std::string _amount) :
        toCurrency(_toCurrency), fromCurrency(_fromCurrency), amount(_amount)
{
    try
    {
        std::ifstream fileApiKey("apiKey.txt");
        std::getline(fileApiKey, apiKey);
        apiKey.insert(0, "apikey: ");
    }
    catch(std::exception e)
    {
        // TODO
        Log::LOG_DEBUG("Nie ma takiego pliku: apiKey.txt");
        Log::LOG_DEBUG(e.what());
        apiKey = "empty";
    }


}

void FixerApiReader::readCurrentRate()
{
    CURL * curl;
    curl = curl_easy_init();
    std::unique_ptr<std::string> outData(new std::string());
    Log::LOG_DEBUG("readCurrentRate");
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
        std::cout << "outData: " << outData.get()->c_str() << std::flush;
    }
}