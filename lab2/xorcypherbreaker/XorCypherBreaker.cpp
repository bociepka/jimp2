//
// Created by Bartek on 12.03.2018.
//

#include "XorCypherBreaker.h"

const std::vector<char> decrypted_text;

std::vector<std::string> dictionary
        {"the", "of", "and", "to", "a", "in", "is", "you", "are", "for", "that", "or", "it", "as", "be", "on",
         "your", "with", "can", "have", "this", "an", "by", "not", "but", "at", "from", "I", "they", "more",
         "will", "if", "some", "there", "what", "about", "which", "when", "one", "their", "all", "also",
         "how", "many", "do", "has", "most", "people", "other", "time", "so", "was", "we", "these", "may",
         "like", "use", "into", "than", "up", "out", "who", "them", "make", "because", "such", "through",
         "get", "work", "even", "different", "its", "no", "our", "new", "film", "just", "only", "see", "used",
         "good", "water", "been", "need", "should", "very", "any", "history", "often", "way", "well", "art",
         "know", "were", "then", "my", "first", "would", "money", "each", "over", "world", "information", "map",
         "find", "where", "much", "take", "two", "want", "important", "family", "those", "example", "while",
         "he", "look", "government", "before", "help", "between", "go", "own", "however", "business", "us",
         "great", "his", "being", "another", "health", "same", "study", "why", "few", "game", "might", "think",
         "free", "too", "had", "hi", "right", "still", "system", "after", "computer", "best", "must", "her",
         "life", "since", "could", "does", "now", "during", "learn", "around", "usually", "form", "meat", "air",
         "day", "place", "become", "number", "public", "read", "keep", "part", "start"};

std::string key_increment(std::string key, int length){
    std::string key_result;
    if (key=="zzz") {
    return "";
    }
    key[length-1]--;
    for (int i=length-1;i>=0;i--){
        if (key[i]==123){
            key[i]='a';
            key[i-1]++;
        }
    }
    return key_result;
}

void decrypt(std::string key, int key_length,const std::vector<char> &cryptogram){
 for(int i=0;i<cryptogram.size();i++){
     decrypted_text[i]=cryptogram[i]^key[i%key_length];
 }
}

std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<string> &dictionary){
    std::string result_key;
    std::string key="aa`";
    do{
        decrypt(key,key_length,cryptogram);

    }while(key_increment(key, key_length)!="");
    return result_key;
}
