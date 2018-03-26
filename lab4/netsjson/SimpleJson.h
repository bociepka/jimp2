//
// Created by Bartek on 26.03.2018.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <map>
#include <vector>

namespace nets {
    class JsonValue {
    public:
        JsonValue();
        JsonValue(std::string string_input);
        JsonValue(int int_input);
        JsonValue(double double_input);
        JsonValue(bool bool_input);
        JsonValue(std::vector<JsonValue> vector_input);
        JsonValue(std::map<std::string,JsonValue> map_input);
        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;
    private:
        std::string string_value;
        int int_value=NULL;
        double double_value=NULL;
        bool bool_value=NULL;
        std::vector<JsonValue> vector_value;
        std::map<std::string,JsonValue> map_value;
    };
    std::string string_change(std::string str);
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H