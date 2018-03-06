#include "DoubleBasePalindromes.h"
#include <string>
#include <bitset>

bool is_palindrome(std::string str) {
    int i = 0;
    int j = str.length() - 1;
    while (i < j) {
        if (str[i] != str[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

std::string int_to_binary_string (int number){
    std::string string_with_zeros = std::bitset< sizeof(int) * 8 >(number).to_string();
    size_t position = string_with_zeros.find("1");
    return string_with_zeros.substr(position,string_with_zeros.length());
}

uint64_t DoubleBasePalindromes(int max_vaule_exculsive){
    uint64_t suma=0;
    for (int i=1;i<max_vaule_exculsive;i++){
        std::string decimal = std::to_string(i);
        std::string binary = int_to_binary_string(i);
        if (is_palindrome(decimal) && is_palindrome(binary)){
            suma += i;
        }
    }
    return suma;
}