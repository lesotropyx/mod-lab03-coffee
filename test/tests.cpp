// Copyright 2022 UNN-IASR
#include <gtest/gtest.h>
#include "Automata.h"
TEST(task1, test1) {
  std :: string napit[] = { "Espresso", "Flat-white", "Raf", "Mokachino"};
  int ceni[] = {100, 210, 230, 300};
  CofeeMachine cof(ceni, napit, 4);
  cof.on();
  cof.getMenu();
  cof.coin(500);
  cof.choice(4);
  cof.check();
  cof.cook();
  cof.finish();
  std :: string result = cof.getState();
  EXPECT_EQ("WAIT", result);
}
TEST(task1, test2) {
  std :: string napit[] = { "Espresso", "Flat-white", "Raf", "Mokachino"};
  int ceni[] = {100, 210, 230, 300};
  CofeeMachine cof(ceni, napit, 4);
  cof.on();
  cof.getMenu();
  cof.coin(500);
  cof.choice(2);
  cof.check();
  std :: string result = cof.getState();
  cof.cook();
  cof.finish();
  EXPECT_EQ("CHECK", result);
}
TEST(task1, test3) {
  std :: string napit[] = { "Espresso", "Flat-white", "Raf", "Mokachino"};
  int ceni[] = {100, 210, 230, 300};
  CofeeMachine cof(ceni, napit, 4);
  cof.on();
  cof.getMenu();
  cof.coin(500);
  cof.choice(2);
  cof.cancel();
  cof.coin(0);
  cof.choice(3);
  cof.check();
  cof.cook();
  cof.finish();
  int result = cof.cash;
  EXPECT_EQ(270, result);
}