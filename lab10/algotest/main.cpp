//
// Created by Bartek on 15.05.2018.
//

#include "Algo.h"

int main(){
//    std::vector<int> s = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
//    std::vector<int> s2 = algo::Sort(s);
//    algo::SortInPlace(&s);
//    for (auto a : s) {
//        std::cout << a << " ";
//    }
//    std::cout << '\n';



    std::vector< std::pair <int,int> > vect;

    int arr[] = {10, 20, 5, 40 };
    int arr1[] = {30, 60, 20, 50};
    int n = sizeof(arr)/sizeof(arr[0]);


    for (int i=0; i<n; i++)
        vect.push_back( std::make_pair(arr[i],arr1[i]) );


    for (int i=0; i<n; i++)
    {
        std::cout << vect[i].first << " "
             << vect[i].second << std::endl;
    }
    std::cout << std::endl;

    algo::SortByFirstInPlace(&vect);

    for (int i=0; i<n; i++)
    {
        std::cout << vect[i].first << " "
                  << vect[i].second << std::endl;
    }
    std::cout << std::endl;

    algo::SortBySecondInPlace(&vect);

    for (int i=0; i<n; i++)
    {
        std::cout << vect[i].first << " "
                  << vect[i].second << std::endl;
    }
    std::cout << std::endl;




    return 1;
}