#include <gtest/gtest.h>
#include "Parallelogram.h"

// test for wrong perimeter calculation
TEST(ParallelogramTests, FailingTest_Perimeter) {
shapes::Parallelogram p(shapes::Side(10), shapes::Side(20), shapes::Angle(60.0));
// should be 60 (2 * (10 + 20)), but the bug returns 40
ASSERT_EQ(p.getPerimeter(), 60);
}

// test for wrong area calculation
TEST(ParallelogramTests, FailingTest_Area) {
shapes::Parallelogram p(shapes::Side(10), shapes::Side(20), shapes::Angle(30.0));
// should be around 100.0, but the bug causes wrong result
ASSERT_NEAR(p.getArea(), 100.0, 0.01);
}

// test for wrong kind identification
TEST(ParallelogramTests, FailingTest_Kind) {
shapes::Parallelogram p(shapes::Side(10), shapes::Side(20), shapes::Angle(90.0));
// should be a rectangle, but may fail due to a bug
ASSERT_EQ(p.getKind(), shapes::Parallelogram::Kind::RECTANGLE);
}

// test for correct perimeter calculation
TEST(ParallelogramTests, PassingTest_Perimeter) {
shapes::Parallelogram p(shapes::Side(10), shapes::Side(10), shapes::Angle(60.0));
// should be 40 for this shape
ASSERT_EQ(p.getPerimeter(), 40);
}

// test for correct area calculation for square
TEST(ParallelogramTests, PassingTest_Area) {
shapes::Parallelogram p(shapes::Side(10), shapes::Side(10), shapes::Angle(90.0));
// should be around 100.0 for a square
ASSERT_NEAR(p.getArea(), 100.0, 0.01);
}

// test for correct kind identification for rhombus
TEST(ParallelogramTests, PassingTest_Kind) {
shapes::Parallelogram p(shapes::Side(10), shapes::Side(10), shapes::Angle(60.0));
// both sides are equal, so it should be a rhombus
ASSERT_EQ(p.getKind(), shapes::Parallelogram::Kind::RHOMBUS);
}
