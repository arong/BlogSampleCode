#include <rapidjson/document.h>

#include <iostream>
#include <string>
#include <typeinfo>
#include <variant>
#include <vector>

template <typename... T>
bool Parse(rapidjson::Value& data, const char* name,
           std::variant<T...>& target) {
  auto it = data.FindMember(name);
  if (it == data.MemberEnd()) {
    std::cerr << "key not found: " << name << std::endl;
    return false;  // 字段不存在
  }

  // 使用 std::visit 处理 std::variant
  return std::visit(
      [&](auto value) {
        using ValueType = std::remove_pointer_t<decltype(value)>;

        if constexpr (std::is_same_v<ValueType, std::string>) {
          if (!it->value.IsString()) {
            std::cerr << "string not match: " << name << std::endl;
            return false;  // 类型不匹配
          }
          *value =
              std::string(it->value.GetString(), it->value.GetStringLength());
        } else if constexpr (std::is_integral_v<ValueType> ||
                             std::is_floating_point_v<ValueType>) {
          if (!it->value.Is<ValueType>()) {
            std::cerr << "integer not found: " << name << std::endl;

            return false;  // 类型不匹配
          }
          *value = it->value.Get<ValueType>();
        } else {
          std::cerr << "unsupported type\n";
          return false;  // 不支持的类型
        }

        return true;  // 解析成功
      },
      target);
}

struct Person {
  bool married = false;
  int id = 0;
  int age = 0;
  double point = 0;
  std::string name;
  std::string email;
};

bool ParsePerson(Person* person, rapidjson::Value& json) {
  std::vector<
      std::tuple<const char*, std::variant<int*, std::string*, double*, bool*>>>
      list = {
          {"id", &person->id},           {"age", &person->age},
          {"name", &person->name},       {"email", &person->email},
          {"married", &person->married}, {"point", &person->point},
      };

  for (auto& [name, variant] : list) {
    if (!Parse(json, name, variant)) {
      return false;  // 解析失败
    }
  }

  return true;  // 解析成功
}

int main() {
  auto response = R"({
    "id": 123,
    "age": 27,
    "name": "华安",
    "email": "hua.an@example.com",
    "married": true,
    "point": 0.99
})";

  rapidjson::Document doc;

  if (doc.Parse(response).HasParseError()) {
    std::cerr << "JSON parse error!" << std::endl;
    return -1;
  }

  Person person;
  if (!ParsePerson(&person, doc)) {
    std::cerr << "Failed to parse person!" << std::endl;
    return -1;
  }

  std::cout << "ID: " << person.id << std::endl;
  std::cout << "Age: " << person.age << std::endl;
  std::cout << "Name: " << person.name << std::endl;
  std::cout << "Email: " << person.email << std::endl;
  std::cout << "Married: " << person.married << std::endl;
  std::cout << "Point: " << person.point << std::endl;

  return 0;
}
