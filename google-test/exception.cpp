#include <gtest/gtest.h>

#include <stdexcept>

void ThrowIfNegative(int value) {
  if (value < 0) {
    throw std::invalid_argument("Negative value not allowed");
  }
}

TEST(BasicUsageTest, TestExceptions) {
  EXPECT_THROW(ThrowIfNegative(-1),
               std::invalid_argument);  // 测试是否抛出指定类型的异常
  EXPECT_ANY_THROW(ThrowIfNegative(-2));  // 测试是否抛出任意异常
  EXPECT_NO_THROW(ThrowIfNegative(1));    // 测试是否不抛出异常
}
