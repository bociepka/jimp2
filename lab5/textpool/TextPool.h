//
// Created by Bartek on 10.04.2018.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H
#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <cstdarg>
#include <iostream>

namespace pool {
    class TextPool {
    public:
//Rule of Five (z usuniętą możliwością kopiowania)
        TextPool();
        ~TextPool();
        TextPool(TextPool &&origin);
        TextPool (std::initializer_list<std::experimental::string_view> init_list);
        TextPool &operator=(TextPool &&text_pool);
        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;

    private:
        std::set <std::experimental::string_view> value;
    };
}

#endif //JIMP_EXERCISES_TEXTPOOL_H
