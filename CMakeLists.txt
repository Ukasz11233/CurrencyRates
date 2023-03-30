cmake_minimum_required(VERSION 3.19)
project(CurrencyRates)


option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif()


add_library(currentRatesLib STATIC src/CurrentRates.cpp)


target_include_directories(currentRatesLib PUBLIC include)
target_include_directories(currentRatesLib PUBLIC extern/curl/include)
target_include_directories(currentRatesLib PUBLIC extern/json/include)

find_package(CURL REQUIRED)
target_link_libraries(currentRatesLib CURL::libcurl)

add_executable(CurrencyRates app/main.cpp)

target_link_libraries(CurrencyRates PUBLIC currentRatesLib)

