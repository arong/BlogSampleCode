#include <rapidjson/document.h>

#include <iostream>

#include "print.h"

int main() {
  rapidjson::Document doc(rapidjson::kObjectType);
  doc.AddMember("name", "华安", doc.GetAllocator());
  doc.AddMember("id", 9527, doc.GetAllocator());
  doc.AddMember("is_intern", true, doc.GetAllocator());
  print(doc);

  auto& allocator = doc.GetAllocator();

  // 添加对象类型的成员
  rapidjson::Value contact(rapidjson::kObjectType);

  rapidjson::Value email;
  email.SetNull();  // 设置为null
  contact.AddMember("email", email, allocator);

  contact.AddMember("twitter", rapidjson::Value(rapidjson::kNullType),
                    allocator);

  doc.AddMember("contact", contact, allocator);
  print(doc);

  // 添加数组类型的成员
  rapidjson::Value friends(rapidjson::kArrayType);
  friends.PushBack("祝枝山", allocator);
  friends.PushBack("文征明", allocator);
  friends.PushBack("徐祯卿", allocator);

  doc.AddMember("friends", friends, allocator);
  print(doc);

  return 0;
}
