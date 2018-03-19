//
// Created by Bartek on 19.03.2018.
//

#include "SmartTree.h"
#include <ostream>
//#include <iostream>
#include <string>
#include <memory>
//#include <vector>

namespace datastructures{

    std::unique_ptr <SmartTree> CreateLeaf(int value){
        std::unique_ptr <SmartTree> leaf = std::make_unique<SmartTree>();
        leaf -> value = value;
        return leaf;
    }
}
