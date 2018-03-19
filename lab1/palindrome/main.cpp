#include "Palindrome.h"
using namespace std;

int main(){
    cout << "1. Sprawdz palindrom" << endl << "2. Wyjscie" << endl;
    int a;
    cin >> a;
    if (a == 2) {
        return 0;
    }
    else{
        cout << "Podaj wyraz do sprawdzenia:";
        string str;
        cin >> str;
        cout << endl << IsPalindrome(str) << endl;
    }
}
