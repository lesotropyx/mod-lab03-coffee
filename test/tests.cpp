// Copyright 2022 UNN-IASR
#include <gtest/gtest.h>
#include "Automata.h"
TEST(task1, test1) {
  int prices[3] = {30, 50, 40};
    std::string menu[3] = {"Raf", "Espresso", "Flat-white"};
    Automata coffeeMachine(prices, menu);

    coffeeMachine.on();
    coffeeMachine.getMenu();
    coffeeMachine.coin(30);

    coffeeMachine.choice(2);
    if (coffeeMachine.check(2)) {
        coffeeMachine.cook();
        coffeeMachine.finish();
    } else {
        coffeeMachine.cancel();
    }
    std::string result = coffeeMachine.getState();
    EXPECT_EQ("WAIT", result);
}
TEST(task1, test2) {
   int prices[3] = {30, 50, 40};
    std::string menu[3] = {"Raf", "Espresso", "Flat-white"};
    Automata coffeeMachine(prices, menu);

    coffeeMachine.on();
    coffeeMachine.getMenu();
    coffeeMachine.coin(50);
    coffeeMachine.choice(2);
    coffeeMachine.check(2);
    std::string result = coffeeMachine.getState();
    coffeeMachine.cook();
    coffeeMachine.finish();
    EXPECT_EQ("CHECK", result);
}
TEST(task1, test3) {
   int prices[3] = {30, 50, 40};
    std::string menu[3] = {"Raf", "Espresso", "Flat-white"};
    Automata coffeeMachine(prices, menu);

    coffeeMachine.on();
    coffeeMachine.getMenu();
    coffeeMachine.coin(50);
    coffeeMachine.choice(1);
    coffeeMachine.cancel();
    coffeeMachine.coin(50);
    coffeeMachine.choice(2);
    coffeeMachine.check(2);
    coffeeMachine.cook();
    coffeeMachine.finish();
    int result = coffeeMachine.getCash();
    EXPECT_EQ(0, result);
}