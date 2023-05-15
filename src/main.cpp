// Copyright 2022 UNN-IASR


#include "Automata.h"
#include "iostream"


int main() {
    Automata coffeeMachine;

    coffeeMachine.getMenu();
    coffeeMachine.on();
    coffeeMachine.coin(50); //купим 2 кофе, должно пройти
    cout<< "Текущее состояние( должно быть ACCEPT): ";
    cout<< coffeeMachine.getState();
    cout<< endl;

    coffeeMachine.choice(2);
    if (coffeeMachine.check(2)) {
        coffeeMachine.cook();
        coffeeMachine.finish();
    } else {
        coffeeMachine.cancel();
    }
    cout<< "Текущее состояние (должно быть WAIT): ";
    std :: string result2 = coffeeMachine.getState();
    cout<< result2;
    return 0;
}
