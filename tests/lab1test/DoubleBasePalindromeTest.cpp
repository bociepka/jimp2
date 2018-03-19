//
// Created by mwypych on 16.02.17.
//
#include <gtest/gtest.h>
#include <DoubleBasePalindromes.h>
#include <vector>

using TestParam = std::pair<int, uint64_t>;

class DoubleBasePalindromeDataDrivenTests : public ::testing::TestWithParam<TestParam> {

};

TEST_P(DoubleBasePalindromeDataDrivenTests, PalindromeShouldReturnExpectedResult) {
  const TestParam &p = GetParam();
  auto expected = p.second;
  auto arg = p.first;
  EXPECT_EQ(expected, DoubleBasePalindromes(arg)) << "Did call DoubleBasePalindrome(" << arg << ")\n";
}

std::vector<TestParam> doubleBasePalindromeTestData
    {{1000000, 872187}, {14560, 18228}, {8989812, 25846868}, {-1, 0}, {300000, 286602}};

INSTANTIATE_TEST_CASE_P(DoubleBasePalindromeTestFixture,
                        DoubleBasePalindromeDataDrivenTests,
                        ::testing::ValuesIn(doubleBasePalindromeTestData));
