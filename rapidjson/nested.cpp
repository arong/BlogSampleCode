#include <rapidjson/document.h>

#include <iostream>

int main() {
  auto response =
      R"({"code":200,"data":{"total":200,"curr":[12345,23456,34564]}})";

  rapidjson::Document doc;

  if (doc.Parse(response).HasParseError()) {
    return -1;
  }

  if (auto it = doc.FindMember("data");
      it != doc.MemberEnd() && it->value.IsObject()) {
    const auto& data = it->value.GetObject();

    if (auto cit = data.FindMember("curr");
        cit != data.MemberEnd() && cit->value.IsArray()) {
      const auto& curr = cit->value.GetArray();
      // range based for
      for (const auto& item : curr) {
        if (item.IsInt()) {
          std::cout << item.GetInt() << std::endl;
        }
      }

      for (auto it = curr.Begin(); it != curr.End(); ++it) {
        if (it->IsInt()) {
          std::cout << it->GetInt() << std::endl;
        }
      }
    }
  }
  return 0;
}
