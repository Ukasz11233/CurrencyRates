#include <gtest/gtest.h>
#include "project/CurrentRates.h"

class testCurrentRate : public ::testing::TestWithParam<double>
{
public:
    void SetUp() override {}

private:
};

TEST_P(testCurrentRate, initalTest)
{
    auto const currentRateInfoExpected = GetParam();
    CurrentRates currentRates(2);
    EXPECT_EQ(currentRateInfoExpected, currentRates.getCurrentRate());
}

std::vector<double> loadTestData()
{
    std::vector<double> testData;
    testData.push_back(2);
    return testData;
}

INSTANTIATE_TEST_CASE_P(Test1,
                        testCurrentRate,
                        ::testing::ValuesIn(loadTestData()));
