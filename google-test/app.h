#pragma once
#include "interface.h"

class App {
 public:
  explicit App(DBInterface* link) : db_(link) {}

  void Setup(const std::string& url) {
    if (!db_->Connect(url)) {
      return;
    }

    auto config = db_->Query("select config from config_table");
    // ... 其他处理
  }

 private:
  DBInterface* db_ = nullptr;
};
