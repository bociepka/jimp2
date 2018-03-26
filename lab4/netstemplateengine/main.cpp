//
// Created by krzysztof on 26.03.18.
//

#include <iostream>
#include "SimpleTemplateEngine.h"

int main(){
    std::unordered_map<std::string, int> unorderedMap={{"string1", 1}, {"string2", 2}, {"string3", 3}, {"string4", 4}};
    for(auto m: unorderedMap){
        std::cout<<m.first<<" "<<m.second<<std::endl;
    }
    return 0;
}