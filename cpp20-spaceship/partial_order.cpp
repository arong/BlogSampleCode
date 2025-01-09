#include <cmath>
#include <compare>
#include <iostream>
#include <limits>

struct CustomFloat {
  double value;

  // For floating point values, we must use partial_ordering
  std::partial_ordering operator<=>(const CustomFloat& other) const {
    // Handle NaN cases first
    if (std::isnan(value) || std::isnan(other.value)) {
      return std::partial_ordering::unordered;
    }
    // Now we can safely compare the values
    if (value < other.value) return std::partial_ordering::less;
    if (value > other.value) return std::partial_ordering::greater;
    return std::partial_ordering::equivalent;
  }

  // We need to explicitly define operator== for partial ordering
  bool operator==(const CustomFloat& other) const {
    // First check for NaN
    if (std::isnan(value) || std::isnan(other.value)) {
      return false;  // NaN is never equal to anything, including itself
    }
    return value == other.value;
  }
};

int main() {
  // Regular number comparisons
  CustomFloat a{0.1}, b{0.10000001};
  CustomFloat c{0.1}, d{0.1};

  // NaN cases
  CustomFloat nan1{std::numeric_limits<double>::quiet_NaN()};
  CustomFloat nan2{std::numeric_limits<double>::quiet_NaN()};

  std::cout << std::boolalpha;
  std::cout << "Testing regular numbers:\n";
  if (auto cmp = a <=> b; cmp == std::partial_ordering::equivalent) {
    std::cout << "0.1 is equivalent to 0.10000001\n";
  } else if (cmp == std::partial_ordering::less) {
    std::cout << "0.1 is less than 0.10000001\n";
  } else if (cmp == std::partial_ordering::greater) {
    std::cout << "0.1 is greater than 0.10000001\n";
  }

  std::cout << "\nTesting equal numbers:\n";
  if (auto cmp = c <=> d; cmp == std::partial_ordering::equivalent) {
    std::cout << "0.1 is equivalent to 0.1\n";
  }

  std::cout << "\nTesting NaN cases:\n";
  if (auto cmp = nan1 <=> a; cmp == std::partial_ordering::unordered) {
    std::cout << "NaN compared with 0.1 is unordered\n";
  }

  if (auto cmp = nan1 <=> nan2; cmp == std::partial_ordering::unordered) {
    std::cout << "NaN compared with NaN is unordered\n";
  }

  // Using regular comparison operators (they should work automatically)
  std::cout << "\nTesting regular comparison operators:\n";
  std::cout << "0.1 < 0.10000001: " << (a < b) << '\n';
  std::cout << "0.1 == 0.1: " << (c == d) << '\n';
  std::cout << "NaN == NaN: " << (nan1 == nan2) << '\n';

  return 0;
}
