#include "Automata.h"
#include <iostream>
#include <string>
CofeeMachine :: CofeeMachine(int* prices_, std :: string* menu_, int kol_) {
  st = OFF , indchoose = -1 , cash = 0;
  prices = prices_, menu = menu_, kol = kol_;
}
void CofeeMachine :: on() {
  if (st == OFF) {
    st = WAIT;
  }
}
void CofeeMachine :: off() {
  if (st == WAIT) {
    st = OFF;
  }
}
void CofeeMachine :: coin(int a) {
  if (st == WAIT || st == ACCEPT) {
    st = ACCEPT;
    cash = cash + a;
  }
}
void CofeeMachine :: cancel() {
  if (st == ACCEPT || st == CHECK) {
    st = WAIT;
    indchoose = -1;
  }
}
void CofeeMachine :: finish() {
  if (st == COOK) {
    st = WAIT;
    indchoose = -1;
    std :: cout<< "Take your drink \n";
  }
}
void CofeeMachine :: cook() {
  if (st == CHECK) {
    st = COOK;
  }
}
void CofeeMachine :: choice(int ind) {
  if (st == ACCEPT) {
    if ( ind >= 1 && ind <= kol ) {
    indchoose = ind - 1; st = CHECK;
    } else {
      indchoose = -1;
    }
  }
}
void CofeeMachine :: check() {
  if (st == CHECK) {
    if (cash >= prices[indchoose] && indchoose != -1) {
      std :: cout << "paying /n";
      cash = cash - prices[indchoose];
    }
  }
}
std :: string CofeeMachine :: getState() {
  switch (st) {
    case OFF : return "OFF";
    case WAIT : return "WAIT";
    case ACCEPT : return "ACCEPT";
    case CHECK : return "CHECK";
    case COOK : return "COOK";
  }
  return " ";
}
void CofeeMachine :: getMenu() {
  std::string menu_;
  std :: cout << "Menu : \n";
    for (int i = 0; i < kol; i++) {
      std :: cout << i+1 <<". "<< menu[i] <<" - ";
      std :: cout << prices[i] << " рублей \n";
    }
}