#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Awards.h"

// InSequence ensures that methods are called in a specific order
using ::testing::InSequence;

// Return is used to specify what value the mocked method should return
using ::testing::Return;

// _ is a wildcard that matches any argument in mock expectations
using ::testing::_;

// mock class for RankList, simulates getNext method
class MockRankList : public awards::RankList {
public:
    MOCK_METHOD(std::string, getNext, (), (override));  // mocks getNext()
};

// mock class for AwardCeremonyActions, simulates all ceremony actions
class MockAwardCeremonyActions : public awards::AwardCeremonyActions {
public:
    MOCK_METHOD(void, playAnthem, (), (override));
    MOCK_METHOD(void, turnOffTheLightsAndGoHome, (), (override));
    MOCK_METHOD(void, awardBronze, (std::string recipient), (override));
    MOCK_METHOD(void, awardSilver, (std::string recipient), (override));
    MOCK_METHOD(void, awardGold, (std::string recipient), (override));
};

// test to check if performAwardCeremony works correctly
TEST(AwardsTests, TestPerformAwardCeremony) {

    MockRankList mockRankList;  // mock for RankList
    MockAwardCeremonyActions mockActions;  // mock for AwardCeremonyActions

    // set the expected order of method calls
    {
        InSequence seq;  // ensures the methods are called in order

        EXPECT_CALL(mockActions, playAnthem()).Times(1);  // expect playAnthem() to be called once

        EXPECT_CALL(mockRankList, getNext())  // expect getNext() to be called once, return "Apple"
                .Times(1)
                .WillOnce(Return("Apple"));
        EXPECT_CALL(mockActions, awardBronze("Apple")).Times(1);  // expect awardBronze("Apple") once

        EXPECT_CALL(mockRankList, getNext())  // expect getNext() to be called once, return "Ball"
                .Times(1)
                .WillOnce(Return("Ball"));
        EXPECT_CALL(mockActions, awardSilver("Ball")).Times(1);  // expect awardSilver("Ball") once

        EXPECT_CALL(mockRankList, getNext())  // expect getNext() to be called once, return "Cat"
                .Times(1)
                .WillOnce(Return("Cat"));
        EXPECT_CALL(mockActions, awardGold("Cat")).Times(1);  // expect awardGold("Cat") once

        EXPECT_CALL(mockActions, turnOffTheLightsAndGoHome()).Times(1);  // expect turnOffTheLightsAndGoHome() once
    }

    // call the function to test with the mock objects
    awards::performAwardCeremony(mockRankList, mockActions);
}
