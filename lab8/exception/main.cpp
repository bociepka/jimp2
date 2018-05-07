//
// Created by Bartek on 24.04.2018.
//

#include <iostream>
using namespace std;

class CircleException{
    // Oznacza ze nie mozna wyrysowac kola
};

class BallException : public CircleException{
    // Oznacza ze nie mozna wyrysowac kuli
};

void drawBall() {
    throw BallException();
}
void drawCircle(){
    throw CircleException();
}

int main(){
    try{
        drawBall();
    }catch(BallException b){
        cout << "Blad podczas rysowania kuli" << endl;
    }catch(CircleException a){
        cout << "Blad podczas rysowania kola" << endl;
    }
    try {
        drawCircle();
    }catch(BallException b){
        cout << "Blad podczas rysowania kuli" << endl;
    }catch(CircleException a){
        cout << "Blad podczas rysowania kola" << endl;
    }

}