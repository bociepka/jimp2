//
// Created by Bartek on 13.03.2018.
//

#include "MinimalTimeDifference.h"
#include <string>
#include <vector>
#include <sstream>
#include <regex>
#include <cmath>
#include <algorithm>

int Roznica(std::string czas1, std::string czas2){
    unsigned int a=minimaltimedifference::ToMinutes(czas1);
    unsigned int b=minimaltimedifference::ToMinutes(czas2);
    return std::min(abs(a-b),abs(b-a));

}
namespace minimaltimedifference {
unsigned int ToMinutes(std::string time_HH_MM){
    int godzina=10*(int(time_HH_MM[0])-48)+int(time_HH_MM[1])-48;
    int minuta=10*(int(time_HH_MM[3])-48)+int(time_HH_MM[4])-48;
    return 60*godzina+minuta;
}

unsigned int MinimalTimeDifference(std::vector<std::string> times){
    unsigned int result=Roznica(times[0],times[1]);
    for(int i=0;i<times.size();i++){
        if (Roznica(times[i],times[i+1])<result){
            result=Roznica(times[i],times[i+1]);
        }
    }
}}