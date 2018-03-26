//
// Created by Bartek on 26.03.2018.
//

#include "SimpleJson.h"
#include <sstream>

namespace nets {
    std::string string_change(std::string str) {
        const char *letters = str.c_str();
        std::string out = "\"";
        size_t size = str.length();
        for (int i = 0; i < size; i++) {
            if (letters[i] == '\\' || letters[i] == '\"') {
                out += '\\';
            }
            out += letters[i];
        }
        out += "\"";
        return out;
    }
    JsonValue::JsonValue(){

    }

    JsonValue::JsonValue(std::string string_input){
        string_value = string_change(string_input);
    }
    JsonValue::JsonValue(double double_input){
        double_value=double_input;
    }
    JsonValue::JsonValue(std::vector<JsonValue> vector_input){
        vector_value=vector_input;
    }
    JsonValue::JsonValue(std::map<std::string,JsonValue> map_input){
        for (auto const &i: map_input) {
            map_value[string_change(i.first)]=i.second;
        }
    }
    JsonValue::JsonValue(bool bool_input) {
        bool_value = bool_input;
    }
    JsonValue::JsonValue(int int_input) {
        int_value = int_input;
    }
    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const
    {   auto i = map_value.find(string_change(name));
        if(i!=map_value.end())
            return std::experimental::make_optional(i->second);
        else
            return {};

    }
    std::string JsonValue::ToString() const {
        std::stringstream out;
        if (int_value != NULL)
            out<<int_value;
        else if (double_value != NULL)
            out<<double_value;
        else if(!string_value.empty() )
            out<<string_value ;
        else if(vector_value.size()>0) {
            out<<"[";
            for (int i=0;i<vector_value.size();i++) {
                if(i==vector_value.size()-1)
                    out<<vector_value[i].ToString();
                else
                    out<<vector_value[i].ToString()+", ";
            }
            out<<"]";
        }
        else if (map_value.size()>0)
        {
            int i=0;

            out<<"{";
            for (auto it=map_value.begin(); it!=map_value.end(); ++it ) {
                i++;
                if(i==map_value.size())
                    out<<it->first<<": "<< it->second.ToString();
                else
                    out<<it->first<<": "<<it->second.ToString()<<", ";
            }
            out<<"}";
        } else {
            if(bool_value)
                out<<"true";
            else
                out<<"false";
        }
        return out.str();
    }

}