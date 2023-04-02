//
// Created by ukasz on 02.04.2023.
//
#include <gtest/gtest.h>
#include <project/FixerApiReader.h>

struct apiReaderInfo
{
    int tmp;
};


class testFixerApiReader : public testing::TestWithParam<apiReaderInfo>
{
public:
};


TEST_P(testFixerApiReader, firstTest)
{
    auto const expectedApiReaderInfo = GetParam();
    FixerApiReader testableReader;
    EXPECT_EQ(expectedApiReaderInfo.tmp, testableReader.getCurrentRate());
}

std::vector<apiReaderInfo> loadTestData()
{
    std::vector<apiReaderInfo> testData;
    testData.push_back({1});
    return testData;
}


INSTANTIATE_TEST_CASE_P(Test2,
                        testFixerApiReader,
                        ::testing::ValuesIn(loadTestData()));