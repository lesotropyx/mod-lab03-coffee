// Copyright 2022 UNN-IASR
#include "Automata.h"
#include <iostream>
#include <string>


void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
    }
}

void Automata::off() {
    if (state == STATES::WAIT) {
        state = STATES::OFF;
    }
}

void Automata::coin(int value) {
    if (state == STATES::WAIT || state == STATES::ACCEPT) {
        state = STATES::ACCEPT;
        cash += value;
    }
}

void Automata::cancel() {
    if (state == STATES::ACCEPT || state == STATES::CHECK) {
        state = STATES::WAIT;
    }
}

void Automata::finish() {
    if (state == STATES::COOK) {
        state = STATES::WAIT;
        std::cout << "Take your drink" << std::endl;
    }
}

void Automata::cook() {
    if (state == STATES::CHECK) {
        state = STATES::COOK;
    }
}

void Automata::choice(int drink) {
    if (state == STATES::ACCEPT) {
        if (drink >= 1 && drink <= 3) {
            indchoose = drink - 1;
            state = STATES::CHECK;
        } else {
            indchoose = -1;
        }
    }
}

bool Automata::check(int drink) {
    if (state == STATES::CHECK) {
        if (cash >= prices[indchoose] && indchoose != -1) {
            cash -= prices[indchoose];
            return true;
        }
        return false;
    }
    return false;
}

void Automata::getMenu() {
    for (int i = 0; i < 3; i++) {
        std::cout << menu[i] << " - " << prices[i] << " рублей" << std::endl;
    }
}

STATES Automata::getState() {
    return state;
}
