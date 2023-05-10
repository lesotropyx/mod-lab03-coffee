// Copyright 2022 UNN-IASR
#include "Automata.h"
#include "iostream"
int main() {
  std :: string napit[] = { "Espresso", "Flat-white", "Raf", "Mokachino" };
  int ceni[] = {100, 210, 230, 300};
  CofeeMachine cof(ceni, napit, 4);
  cof.on();
  cof.getMenu();
  cof.coin(500);
  cof.choice(4);
  cof.check();
  cof.getState();
  cof.cook();
  cof.finish();
  return 0;
}