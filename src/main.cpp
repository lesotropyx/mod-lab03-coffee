// Copyright 2022 UNN-IASR


#include "Automata.h"
#include "iostream"

int main() {
    Automata coffeeMachine;

    coffeeMachine.getMenu();
    coffeeMachine.on();
    coffeeMachine.coin(50); //купим 2 кофе, должно пройти
    std::cout << "Current state: " << coffeeMachine.getState() << std::endl;

    coffeeMachine.choice(2);
    if (coffeeMachine.check(2)) {
        coffeeMachine.cook();
        coffeeMachine.finish();
    } else {
        coffeeMachine.cancel();
    }

    std::cout << "Current state: " << coffeeMachine.getState() << std::endl;

    return 0;
}