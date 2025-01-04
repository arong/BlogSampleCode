#include <gtest/gtest.h>

int Add(int a, int b) { return a + b; }

int Subtract(int a, int b) { return a - b; }

TEST(BasicUsageTest, TestIntegerAndBoolean) {
  EXPECT_EQ(Add(2, 3), 5);        // 测试是否等于
  EXPECT_NE(Add(2, 2), 5);        // 测试是否不等于
  EXPECT_GT(Subtract(10, 5), 3);  // 测试是否大于
  EXPECT_LT(Subtract(5, 10), 0);  // 测试是否小于
  ASSERT_TRUE(Add(1, 1) == 2);    // 测试布尔表达式为真
  ASSERT_FALSE(Add(1, 1) == 3);   // 测试布尔表达式为假
}

// string compare
std::string GetGreeting() { return "Hello, World!"; }

TEST(BasicUsageTest, TestStringComparison) {
  EXPECT_STREQ(GetGreeting().c_str(), "Hello, World!");  // 测试字符串是否相等
  EXPECT_STRNE(GetGreeting().c_str(), "Hi, World!");  // 测试字符串是否不等
}

// float point compare
double Divide(double a, double b) { return a / b; }

TEST(BasicUsageTest, TestFloatingPointComparison) {
  EXPECT_FLOAT_EQ(Divide(1.0, 3.0), 0.33333333f);  // 测试浮点数是否相等
  EXPECT_NEAR(Divide(10.0, 3.0), 3.333, 0.001);  // 测试浮点数是否接近
}
