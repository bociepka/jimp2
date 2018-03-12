//
// Created by Bartek on 12.03.2018.
//

#include "Polybius.h"
#include <string>

char tab[5][5]={{'a','f','l','q','v'},{'b','g','m','r','w'},{'c','h','n','s','x'},{'d','i','o','t','y'},{'e','k','p','u','z'}};

std::string letter_to_code(char letter){
    for(int j=0;j<5;j++){
        for(int k=0;k<5;k++){
            if (letter==' '){
                return "";
            }
            else if (tab[j][k]==letter){
                return std::to_string(k+1)+std::to_string(j+1);
            }
            else if (letter=='j'){
                return "24";
            }
        }
    }
}

char code_to_letter(char y,char x){
    return tab[x-1][y-1];
}

std::string PolybiusCrypt(std::string message){
    std::string result="";
    for(int i=0;i<message.length();i++){
        result+=letter_to_code(message[i]);
    }
    return result;
}

std::string PolybiusDecrypt(std::string crypted){
    std::string result="";
    for(int i=0;i<crypted.length();i+=2){
        result+=code_to_letter(crypted[i]-48,crypted[i+1]-48);
    }
    return result;
}