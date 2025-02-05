#include <rapidjson/document.h>

#include <iostream>

int main() {
  auto input = R"({"name": "华安", "id": 9527})";
  rapidjson::Document doc;

  doc.Parse(input);
  if (doc.HasParseError()) {
    return -1;
  }

  // HasMember + Is + Get
  if (doc.HasMember("name") && doc["name"].IsString()) {
    std::string name = doc["name"].GetString();
    std::cout << "name is: " << name << std::endl;
  }
  if (doc.HasMember("id") && doc["id"].IsInt()) {
    int id = doc["id"].GetInt();
    std::cout << "id is: " << id << std::endl;
  }

  // Find
  if (auto it = doc.FindMember("name");
      it != doc.MemberEnd() && it->value.IsString()) {
    std::string name = it->value.GetString();
    std::cout << "name is: " << name << std::endl;
  }
  if (auto it = doc.FindMember("id");
      it != doc.MemberEnd() && it->value.IsInt()) {
    auto id = it->value.GetInt();
    std::cout << "id is: " << id << std::endl;
  }

  return 0;
}
