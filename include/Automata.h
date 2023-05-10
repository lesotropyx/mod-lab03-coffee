// Copyright 2022 UNN-IASR
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include<iostream>
#include<string>
class CofeeMachine{
 public:
  CofeeMachine(int* prices_, std :: string* menu_, int kol_);
  int cash;
  void on();
  void off();
  void coin(int a);
  void getMenu();
  std :: string getState();
  void choice(int ind);
  void check();
  void cancel();
  void cook();
  void finish();
 private:
  int kol;
  std :: string* menu;
  int* prices;
  enum state { OFF, WAIT, ACCEPT, CHECK, COOK };
  int indchoose;
  state st;
};
#endif  // INCLUDE_AUTOMATA_H_