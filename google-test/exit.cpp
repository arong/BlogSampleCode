#include <gtest/gtest.h>

#include <cstdlib>

// 遇到0则进程退出
void TerminateIfZero(int value) {
  if (value == 0) {
    std::exit(EXIT_FAILURE);
  }
}

TEST(BasicUsageTest, TestExit) {
  // 测试是否退出并匹配退出码
  EXPECT_EXIT(TerminateIfZero(0), ::testing::ExitedWithCode(EXIT_FAILURE), "");

  // 测试正常情况是否不退出
  EXPECT_NO_THROW(TerminateIfZero(1));
}
