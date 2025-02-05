#include <rapidjson/document.h>
#include <rapidjson/pointer.h>

#include <iostream>

int main() {
  auto response = R"({
    "code": 200,
    "data": {
        "id": 123,
        "name": "华安",
        "avatar": {
            "image": {
                "medium": "https://image.com/hua.an.jpg",
                "thumbnail": "https://image.com/hua.an-thumbnail.jpg"
            }
        }
    }
})";

  rapidjson::Document doc;

  if (doc.Parse(response).HasParseError()) {
    std::cerr << "JSON parse error!" << std::endl;
    return -1;
  }

  // 使用 RapidJSON 的 Pointer 解析 JSONPath
  const char* jsonpath = "/data/avatar/image/thumbnail";
  rapidjson::Pointer pointer(jsonpath);

  // 获取 JSONPath 对应的值
  if (rapidjson::Value* value = pointer.Get(doc)) {
    if (value->IsString()) {
      std::cout << "Thumbnail URL: " << value->GetString() << std::endl;
    } else {
      std::cerr << "Thumbnail is not a string!" << std::endl;
    }
  } else {
    std::cerr << "Thumbnail not found!" << std::endl;
  }

  return 0;
}
