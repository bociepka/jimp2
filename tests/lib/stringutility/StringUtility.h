//
// Created by mwypych on 24.02.17.
//

#ifndef JIMP_EXERCISES_STRINGUTILITY_H
#define JIMP_EXERCISES_STRINGUTILITY_H

#include <string>
#include <sstream>
#include <ostream>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>

namespace utility {

//template <typename T>
//std::string ToString(std::vector<T> v);
//
//template <typename T>
//std::string ToString(T t);

template<typename T>
std::string ToString(T t) {
  return std::to_string(t);
}

template<typename T>
std::string ToString(const std::vector<T> &v) {
  std::vector<std::string> tmp;
  std::stringstream ss;
  ss << "[";
  std::transform(begin(v), end(v), std::back_inserter(tmp), [](const T &str) { return ToString(str); });
  std::copy(begin(tmp), end(tmp), std::ostream_iterator<std::string>(ss, ", "));
  ss << "]";
  return ss.str();
}

template<typename T>
std::string ToString(const std::set<T> &v) {
  std::vector<std::string> tmp;
  std::stringstream ss;
  ss << "[";
  std::transform(begin(v), end(v), std::back_inserter(tmp), [](const T &str) { return ToString(str); });
  std::copy(begin(tmp), end(tmp), std::ostream_iterator<std::string>(ss, ", "));
  ss << "]";
  return ss.str();
}


template<typename T>
T FromString(const std::string &value) {
  T v{};
  std::istringstream ss(value);
  ss >> v;
  return v;
}

bool MatchesUpToExtraNewLine(const std::string &expected, const std::string &result);

};

#endif //JIMP_EXERCISES_STRINGUTILITY_H
