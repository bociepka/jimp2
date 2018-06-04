//
// Created by Bartek on 22.05.2018.
//

#include <FactoryMethod.h>

int main(){

    int first_int = 3;
    int second_int = 7;
    std::cout << factoryMethod::Add(first_int, second_int)<<std::endl;
    double first_double = 3.1;
    double second_double = 7;
    std::cout << factoryMethod::Add(first_double, second_double)<<std::endl;
    std::complex<double> first_complex = 2.6;
    std::complex<double> second_complex = 8.12;
    std::cout << factoryMethod::Add(first_complex, second_complex)<<std::endl;
    std::vector<int> int_vector = {1,2,3,4,5};
    std::cout << factoryMethod::Mean(int_vector)<<std::endl;
    std::vector<double> double_vector = {1.2,2.3,3.4,4.5,5.6};
    std::cout << factoryMethod::Mean(double_vector)<<std::endl;

    int a = 10;
    int* pointer = &a;
    std::cout<<factoryMethod::Value(pointer);

}
