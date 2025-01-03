module;

#include <string>
#include <utility>

export module complex;

export namespace complex {
class Person {
 public:
  Person(unsigned age, std::string name) : age_(age), name_(std::move(name)) {}

  [[nodiscard]] std::string Name() const { return name_; }
  [[nodiscard]] unsigned Age() const { return age_; }

 private:
  unsigned age_;
  std::string name_;
};
}  // namespace complex
