//
// Created by Bartek on 10.04.2018.
//

#ifndef JIMP_EXERCISES_ACADEMIA_H
#define JIMP_EXERCISES_ACADEMIA_H
#include<string>
using ::std::string;

namespace academia {
    class StudyYear {
    public:
        StudyYear();

        StudyYear(int value);

        ~StudyYear();

        bool operator<(const StudyYear other);

        StudyYear operator++();

    private:
        int _value;
    };

    class Student {

    private:
        string id;
        string first_name;
        string last_name;
        string program;
        StudyYear year;
    };
}
#endif //JIMP_EXERCISES_ACADEMIA_H
