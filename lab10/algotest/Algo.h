//
// Created by Bartek on 15.05.2018.
//

#ifndef JIMP_EXERCISES_ALGOTEST_H
#define JIMP_EXERCISES_ALGOTEST_H
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>

namespace algo {
    void SortInPlace(std::vector<int> *v);

    std::vector<int> Sort(const std::vector<int> &v);

    void SortByFirstInPlace(std::vector<std::pair<int, int>> *v);

    void SortBySecondInPlace(std::vector<std::pair<int, int>> *v);

    std::set<std::string> Keys(const std::map<std::string, int> &m);

    std::vector<int> Values(const std::map<std::string, int> &m);

    std::map<std::string, int> DivisableBy(const std::map<std::string, int> &m, int divisor);

    std::vector<std::string> MapToString(const std::vector<double> &v);

    std::string Join(const std::string &joiner, const std::vector<double> &v);

    int Sum(const std::vector<int> &v);

    int Product(const std::vector<int> &v);

    bool Contains(const std::vector<int> &v, int element);

    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key);

    bool ContainsValue(const std::map<std::string, int> &v, int value);

    std::vector<std::string> RemoveDuplicates(const std::vector<std::string> &v);

    void RemoveDuplicatesInPlace(std::vector<std::string> *v);

    void InitializeWith(int initial_value, std::vector<int> *v);

    std::vector<int> InitializedVectorOfLength(int length, int initial_value);

    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out);

    int HowManyShortStrings(const std::vector<std::string> &v, int inclusive_short_length);
}
#endif //JIMP_EXERCISES_ALGOTEST_H
