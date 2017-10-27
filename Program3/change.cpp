////////////////////////////////////////////////////////////////////////////////
//  change.cpp
//  Program file implementing solution to Program 3: Dynamic Duo.
//  Solution to making change.
//
//  Yangzi Jiang, Collin Epstein
//  10/26/17
//  CSC321
//  Dr. Mossinghoff
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <iostream>
#include "coins.h"

using namespace std;

int mait(){
    
    // intitialize program
    Coins coinTest;
    coinTest.initializeTrial();
    
    // commence value trials
    cout << "Enter amount to test, or enter -1 to exit: ";
    int testVal;
    cin >> testVal;
    
    // repeat greedy and dynamic programming trials until user exits
    while(testVal >= 0){
        coinTest.greedy(testVal);
        coinTest.printGreedy();
        coinTest.optimal(testVal);
        coinTest.printOptimal();
        coinTest.compare();

        // propmt user for new instructions
        cout << "Enter amount to test, or enter -1 to exit: ";
        cin >> testVal;
    }
    
    cout << "Thank you for playing!" << endl;
    
    return 0;
}
