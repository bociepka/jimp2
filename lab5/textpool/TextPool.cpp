//
// Created by Bartek on 10.04.2018.
//

#include "TextPool.h"

namespace pool{


    TextPool::TextPool() {
    }

    TextPool::~TextPool() {
        value.clear();
    }

    TextPool::TextPool(std::initializer_list<std::experimental::string_view> init_list) {
        value = init_list;
    }

    TextPool::TextPool(TextPool &&origin): value{nullptr}{
        std::swap(value, origin.value);
    }

    TextPool &TextPool::operator=(TextPool &&text_pool) {
        if(&text_pool == this){
            return *this;
        }
        else{
            value.clear();
            std::swap(value, text_pool.value);
        }
    }

    std::experimental::string_view TextPool::Intern(const std::string &str) {

        for(auto text : value){
            if(text == str){
                return text;
            }
        }

        value.insert(std::experimental::string_view(str));

        for(auto a : value){
            if(a == str){
                return a;
            }
        }

    }

    size_t TextPool::StoredStringCount() const {
        size_t result = 0;
        for(auto a : value){
            if(a != "\0"){result++;};
        }
        return result;
    }


}