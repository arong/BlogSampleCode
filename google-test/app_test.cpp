#include "app.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

class MockDatabase : public DBInterface {
 public:
  MOCK_METHOD(bool, Connect, (const std::string& url), (override));
  MOCK_METHOD(std::string, Query, (const std::string& query), (override));
};

TEST(MockTest, TestConnectFail) {
  MockDatabase db;

  // 设置返回值为false, 用来模拟调用失败
  EXPECT_CALL(db, Connect("test_url"))
      .Times(1)
      .WillOnce(::testing::Return(false));

  App app(&db);
  app.Setup("test_url");
}

TEST(MockTest, TestConnectSuccess) {
  MockDatabase db;

  // 设置返回值为true, 模拟调用成功
  EXPECT_CALL(db, Connect("success_url"))
      .Times(1)
      .WillOnce(::testing::Return(true));

  // APP中的逻辑, 在Connect成功之后会进行Query
  EXPECT_CALL(db, Query("select config from config_table"))
      .Times(1)
      .WillOnce(::testing::Return("mocked result"));

  App app(&db);
  app.Setup("success_url");
}
