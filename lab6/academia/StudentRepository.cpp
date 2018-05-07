//
// Created by Bartek on 10.04.2018.
//

#include "StudentRepository.h"
namespace academia {
    StudyYear::StudyYear() {

    }

    StudyYear::StudyYear(int value) {
        this->_value = value;
    }

    StudyYear::~StudyYear() {

    }

    bool StudyYear::operator<(const StudyYear other){
        if (this->_value<other._value)
            return 1;
        else
            return 0;
    }

    StudyYear StudyYear::operator++() {
        this->_value++;
        return *this;
    }
}