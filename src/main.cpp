// Copyright 2022 UNN-IASR


#include "Automata.h"
#include "iostream"


int main() {
    Automata coffeeMachine;

    coffeeMachine.getMenu();
    coffeeMachine.on();
    coffeeMachine.coin(50); //купим 2 кофе, должно пройти
    std::cout<< "Текущее состояние( должно быть ACCEPT): ";
    std::cout<< coffeeMachine.getState();
    std::cout<<  std::endl;

    coffeeMachine.choice(2);
    if (coffeeMachine.check(2)) {
        coffeeMachine.cook();
        coffeeMachine.finish();
    } else {
        coffeeMachine.cancel();
    }
    std::cout<< "Текущее состояние (должно быть WAIT): ";
    std :: string result2 = coffeeMachine.getState();
    std::cout<< result2;
    return 0;
}
