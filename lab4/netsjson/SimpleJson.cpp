//
// Created by Bartek on 26.03.2018.
//
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <experimental/optional>
#include <sstream>
#include <ostream>
#include <regex>
#include "SimpleJson.h"
using ::nets::JsonValue;
using ::std::vector;
using ::std::map;
using ::std::cout;
using ::std::endl;
using ::std::string;
using ::std::literals::operator""s;

namespace nets{

    JsonValue::JsonValue(){};
    JsonValue::JsonValue (std::string string_input){
        value_string = std::experimental::make_optional(string_input);
    }
    JsonValue::JsonValue(int int_input){
        value_int = std::experimental::make_optional(int_input);
    }
    JsonValue::JsonValue(double double_input){
        value_double = std::experimental::make_optional(double_input);
    }
    JsonValue::JsonValue(bool bool_input){
        value_bool = std::experimental::make_optional(bool_input);
    }
    JsonValue::JsonValue(std::vector <JsonValue> vector_input){
        value_vector=std::experimental::make_optional(vector_input);
    }
    JsonValue::JsonValue(std::map<std::string, JsonValue> map_input){
        value_map = std::experimental::make_optional(map_input);
    }
    JsonValue::~JsonValue(){};

    std::experimental::optional <JsonValue> JsonValue::ValueByName(const std::string &name) const{
        if(value_map){
            for(auto &i: *value_map){
                if(i.first==name){
                    auto result = std::experimental::make_optional(i.second);
                    return result;
                }
            }
        }
    }

    std::string JsonValue::ToString() const{
        std::string result="";

        if(value_string){
            std::string helping_str=*value_string;
            result="\""+*value_string+"\"";
        }

        if(value_int){
            result = std::to_string((*value_int));
        }

        if(value_double) {
            std::ostringstream strs;
            strs << *value_double;
            result = strs.str();
        }

        if(value_bool){
            if((*value_bool)){
                result = "true";
            }else{
                result = "false";
            }
        }

        if(value_vector){
            result="[";
            bool first = true;
            for(auto a: (*value_vector)){
                if(first){
                    result= result + a.ToString();
                    first=false;
                }else{
                    result= result +", "+ a.ToString();
                }
            }
            result=result+"]";
        }

        if(value_map){
            for(auto &b: *value_map){
                result = b.first + b.second.ToString();
            }
        }

        return result;
    }
}