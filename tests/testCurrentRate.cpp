#include <gtest/gtest.h>
#include "project/CurrentRates.h"
#include "../currencies.h"

struct expectedValues
{
    std::string currency;
    double value;
};

class testCurrentRate : public ::testing::TestWithParam<expectedValues>
{
public:
    void SetUp() override {}

private:
};

TEST_P(testCurrentRate, initalTest)
{
    auto const currentRateInfoExpected = GetParam();
    CurrentRates currentRates;
    EXPECT_EQ(currentRateInfoExpected.value, currentRates.getCurrentRate(currentRateInfoExpected.currency));
}

std::vector<expectedValues> loadTestData()
{
    std::vector<expectedValues> testData{
        {.currency = "EUR", .value = 0},
        {.currency = "USD", .value = 0}};
    return testData;
}

INSTANTIATE_TEST_CASE_P(testConstructor,
                        testCurrentRate,
                        ::testing::ValuesIn(loadTestData()));
