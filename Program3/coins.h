////////////////////////////////////////////////////////////////////////////////
//  coins.h
//  Program file implementing solution to Program 3: Dynamic Duo.
//  Header file for coins class for making change.
//
//  Yangzi Jiangon, Collin Epstein
//  10/26/17
//  CSC321
//  Dr. Mossinghoff
////////////////////////////////////////////////////////////////////////////////

#ifndef coins_h
#define coins_h

#include <iostream>
#include <stdio.h>

using namespace std;


class Coins{
    
  public:
    Coins();
    ~Coins();
    void resize(int);
    void topDown(int);
    void initializeTrial();
    void greedy(int);
    void printGreedy();
    void optimal(int);
    void printOptimal();
    void compare();
  private:
    int numCoins;
    int* values;
    string coinsUsed;
    int countGreedy;
    int countOptimal;
    int tableSize;
    int* coinCounts;
    void topDownHelper(int, const int, const int);
};

#endif /* coins_h */
