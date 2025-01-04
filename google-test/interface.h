#pragma once
#include <string>

class DBInterface {
 public:
  virtual bool Connect(const std::string& url) = 0;
  virtual std::string Query(const std::string& query) = 0;

  // 必须要有一个virtual的析构函数
  virtual ~DBInterface() = default;
};
