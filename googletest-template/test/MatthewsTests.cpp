#include <gtest/gtest.h>
#include "Matthews.h"

using sequence::checkMatthewsOutcome;
using sequence::MatthewsOutcome;



TEST(MatthewsTests, TestMinusOneCycle) {
// when number is -1, it should return MatthewsOutcome::MINUS_ONE_CYCLE
int64_t number = -1;
ASSERT_EQ(checkMatthewsOutcome(number), MatthewsOutcome::MINUS_ONE_CYCLE);
}

TEST(MatthewsTests, TestMinusTwoCycle) {
// when number is -2, it should return MatthewsOutcome::MINUS_TWO_CYCLE
int64_t number = -2;
ASSERT_EQ(checkMatthewsOutcome(number), MatthewsOutcome::MINUS_TWO_CYCLE);
}

TEST(MatthewsTests, TestMinusFourCycle) {
// when number is -4, it should return MatthewsOutcome::MINUS_TWO_CYCLE
int64_t number = -4;
ASSERT_EQ(checkMatthewsOutcome(number), MatthewsOutcome::MINUS_TWO_CYCLE);
}


TEST(MatthewsTests, TestZeroRemainder) {
// when number is 0, it should return MatthewsOutcome::ZERO
int64_t number = 0;
ASSERT_EQ(checkMatthewsOutcome(number), MatthewsOutcome::ZERO);
}

TEST(MatthewsTests, TestContinuationRemainderOne) {
// test when remainder is 1
int64_t number = 7;
// the number should keep changing according to the formula (7 * number + 2) / 3
ASSERT_NE(checkMatthewsOutcome(number), MatthewsOutcome::ZERO);
}

TEST(MatthewsTests, TestContinuationOtherRemainder) {
// test when remainder is 2
int64_t number = 8;
// the number should keep changing according to the formula (number - 2) / 3
ASSERT_NE(checkMatthewsOutcome(number), MatthewsOutcome::ZERO);
}
