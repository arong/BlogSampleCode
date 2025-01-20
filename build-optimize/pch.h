#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

template <int N>
struct Sum {
  static const int value = N + Sum<N - 1>::value;
};

template <>
struct Sum<0> {
  static const int value = 0;
};
