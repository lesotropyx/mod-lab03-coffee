// Copyright 2022 UNN-IASR
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include<iostream>
#include<string>
enum class STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
public :
    Automata() : cash(0), state(STATES::OFF), indchoose(-1) {}
    void on();
    void off();
    void coin(int value);
    void getMenu();
    STATES getState();
    void choice(int drink);
    bool check(int drink);
    void cancel();
    void cook();
    void finish();

private :
    int cash;
    int indchoose;
    std::string menu[3] = {"Raf", "Espresso", "Flat-white"};
    int prices[3] = {30, 50, 40};
    STATES state;
};
#endif  // INCLUDE_AUTOMATA_H_
