//
// Created by Bartek on 15.05.2018.
//

#include "Algo.h"
#include <iostream>

namespace algo {

    bool sortbysec(const std::pair<int, int> &a,
                   const std::pair<int, int> &b) {
        return (a.second < b.second);
    }

    void SortInPlace(std::vector<int> *v) {
        std::sort(v->begin(), v->end());
    }

    std::vector<int> Sort(const std::vector<int> &v) {
        std::vector<int> result;
//    std::transform(v.begin(), v.end(), back_inserter(result), [](int current){return})
        std::copy(v.begin(), v.end(), std::back_inserter(result));
        std::sort(result.begin(), result.end());
        return result;
    }

    void SortByFirstInPlace(std::vector<std::pair<int, int>> *v) {
        std::sort(v->begin(), v->end());
    }

    void SortBySecondInPlace(std::vector<std::pair<int, int>> *v) {
        std::sort(v->begin(), v->end(), sortbysec);
    }

    bool Contains(const std::vector<int> &v, int element){
    return (std::find(v.begin(), v.end(), element)!=v.end());
    }
    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out) {
        std::copy_n(v.cbegin(), n_elements, std::back_inserter(*out));
    }

    void InitializeWith(int initial_value, std::vector<int> *v) {
        std::fill(v->begin(), v->end(), initial_value);
    }

    std::vector<int> InitializedVectorOfLength(int length, int initial_value) {
        std::vector<int> result;
        std::fill_n(std::back_inserter(result), length, initial_value);
        return result;
    }

    std::vector<std::string> MapToString(const std::vector<double> &v) {
        std::vector<std::string> s;
        std::transform(v.begin(), v.end(), std::back_inserter(s), [](double i){
            return std::to_string(i);
        });
        return s;
    }

    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key) {
        return (v.find(key)!=v.end());
    }

    std::set<std::string> Keys(const std::map<std::string, int> &m) {
        std::set<std::string> result;
        std::transform(m.begin(), m.end(), std::inserter(result, result.begin()), [](auto x){
            return x.first;
        });
        return result;
    }

    bool ContainsValue(const std::map<std::string, int> &v, int value) {
        std::vector<int> result;
        std::transform(v.begin(), v.end(), std::back_inserter(result), [](auto x){
            return x.second;
        });
        return (std::find(result.begin(), result.end(), value)!= result.end());
    }

    std::vector<int> Values(const std::map<std::string, int> &m) {
        std::vector<int> result;
        std::transform(m.begin(), m.end(), std::back_inserter(result), [](auto x){
            return x.second;
        });
        return result;
    }

    std::vector<int> DivisableBy(const std::vector<int> &m, int divisor) {
        std::vector<int> result;
        std::copy_if(m.begin(), m.end(), std::back_inserter(result), [divisor](auto x) {return (x%divisor==0);} );
        return result;
    }
}