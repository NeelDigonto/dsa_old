#pragma once
#include <any>
#include <bitset>
#include <chrono>
#include <cstdarg>
#include <cstddef>
#include <cstdlib>
#include <filesystem>
#include <functional>
#include <initializer_list>
#include <optional>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <utility>
#include <variant>

//#include <memory>
//#include <memory_resource>
//#include <scoped_allocator>
#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <deque>
#include <exception>
#include <forward_list>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdexcept>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>
//#include <execution>

#include <algorithm>
#include <cmath>
#include <complex>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <random>
#include <ratio>
#include <regex>
#include <sstream>
#include <streambuf>

/*
#include <bits/stdc++.h>
using namespace std;
using sz = std::size_t;
*/

using sz = std::size_t;

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
  os << "[ ";
  for (auto it = v.cbegin(); it != v.cend(); ++it) os << *it << " ";
  os << "]";
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os,
                         const std::vector<std::vector<T>>& v) {
  for (auto row = v.cbegin(); row != v.cend(); ++row) os << *row << std::endl;
  return os;
}

namespace util {

template <typename FwdIt>
std::ostringstream printLinearDS(FwdIt _first, FwdIt _last) {
  std::ostringstream oss;

  if (distance(_first, _last) == 1)
    oss << *_first;
  else {
    for (auto it = _first; it != _last - 1; ++it) oss << *it << ", ";
    oss << *prev(_last);
  }

  return oss;
}

template <typename C>
std::ostringstream print(const C& _c) {
  return printLinearDS(_c.begin(), _c.end());
}

template <typename Func, typename... Args>
void benchmark(const std::string& _test_name, Func _func, Args&&... _args) {
  auto start = std::chrono::high_resolution_clock::now();

  _func(std::forward<Args>(_args)...);
  auto finish = std::chrono::high_resolution_clock::now();

  double elapsed_seconds =
      std::chrono::duration_cast<std::chrono::duration<double>>(finish - start)
          .count();

  std::cout << _test_name << "took (seconds): " << elapsed_seconds << std::endl;
}

template <typename T>
void forEach(T _iterable,
             void (*_lambda)(const typename T::value_type&, std::size_t)) {
  typename T::const_iterator iterator = _iterable.begin();
  std::size_t index = 0;

  while (iterator != _iterable.end()) _lambda(*iterator++, index++);
}

template <typename T>
[[nodiscard]] T map(T _iterable,
                    auto(*_lambda)(const typename T::value_type&, std::size_t)
                        ->typename T::value_type) {
  typename T::const_iterator iterator = _iterable.begin();

  std::size_t index = 0;
  std::array<typename T::value_type, _iterable.size()> new_iterable;

  while (iterator != _iterable.end())
    new_iterable[index] = _lambda(*iterator++, index++);

  return new_iterable;
}

}  // namespace util
