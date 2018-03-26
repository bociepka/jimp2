//
// Created by Bartek on 26.03.2018.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <experimental/optional>
#include <string>
using ::std::vector;
using ::std::map;
using ::std::cout;
using ::std::endl;
using ::std::string;
using ::std::literals::operator""s;

namespace nets{
class JsonValue{
public:
    JsonValue();
    JsonValue(int int_input);
    JsonValue(double double_input);
    JsonValue(bool bool_input);
    JsonValue(string string_input);
    JsonValue(vector <JsonValue> vector_input);
    JsonValue(map <string, JsonValue> map_input);
    ~JsonValue();

    std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
    std::string ToString() const;

private:
    std::experimental::optional<std::string>  value_string;
    std::experimental::optional<int>  value_int;
    std::experimental::optional<double>  value_double;
    std::experimental::optional<bool>  value_bool;
    std::experimental::optional<std::vector<JsonValue>> value_vector;
    std::experimental::optional<std::map <std::string, JsonValue>> value_map;
};
}


#endif //JIMP_EXERCISES_SIMPLEJSON_H
