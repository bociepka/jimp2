//
// Created by krzysztof on 16.04.18.
//

#include "WordCounter.h"
using namespace datastructures;

Word::Word(std::string str) {
    word = str;
}

Counts::Counts(int number) {
    counts = number;
}

bool Word::operator <(const Word &qaqa) const{
    return (word < qaqa.word);
}

bool Word::operator ==(const Word &fafa) const{
    return (word == fafa.word);
}

bool Counts::operator<(const Counts &nana) const{
    return (counts < nana.counts);
}

bool Counts::operator>(const Counts &lala) const{
    return (counts > lala.counts);
}

bool Counts::operator==(const Counts &haha) const{
    return (counts == haha.counts);
}

Counts &Counts::operator++() {
    counts++;
}

WordCounter::WordCounter() {
    distinct = 0;
    total = 0;
}

WordCounter::WordCounter(std::initializer_list<Word> list_ini) {
    distinct = 0;
    total = 0;
    int check;
    for (auto every_word : list_ini){
        total++;
        check = 1;
        for(std::pair<Word, Counts> &my_iterator : list_list) {
            if (list_list.empty()) break;
            else if (my_iterator.first.word == every_word.word) {
                ++my_iterator.second;
                check = 0;
                break;
            }
        }
        if(check){
            Counts new_word{1};
            list_list.emplace_back(std::make_pair(every_word,new_word));
            distinct++;
        }
    }
    for(std::pair<Word, Counts> &iterator : list_list) {
        std::cout << iterator.first.word << " " << iterator.second.counts << std::endl;
    }
}

int WordCounter::operator[](const std::string &gaga) {
    for(std::pair<Word, Counts> &iterator : list_list){
        if(iterator.first.word == gaga){
            return iterator.second.counts;
        }
    }
    return 0;
}

int WordCounter::DistinctWords() {
    return distinct;
}

int WordCounter::TotalWords() {
    return total;
}

std::set<Word> WordCounter::Words(){
    std::set<Word> my_set;
    for(auto &iterator_l : list_list){
        my_set.emplace(iterator_l.first);
    }
    return my_set;
}
