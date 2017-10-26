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

int main(){
    
    Coins coinTest;
    coinTest.initializeTrial();
    /*
    // determine number of coins from user input
    cout << "Number of coins bigger than one cent? ";
    int numC;
    cin >> numC;
    
    // input validation
    while(numC < 1){
        cout << "Must use at least one coint: ";
        cin >> numC;
    }
    cout << endl;
    
    int* values = new int[++numC]; // allocate coin values array
    
    // determine coin values from user input
    cout << "Enter the values of the these coins in increasing order." << endl;
    cout << "   Coin Value 1: 1" << endl; // always use penny, guarantee result
    values[0] = 1;
    
    for (int i = 1; i < numC; i++){
        cout << "   Coin value " << i + 1 << ": ";
        cin >> values[i];
        
        // input validation
        while(values[i] < 2){
            cout << "    Each coin must have a value greater than one: ";
            cin >> values[i];
        }
    }
    cout << endl;
    */
    /*
    // for testing - see coin values
    for (int i = 0; i < numC; i++){
        cout << values[i] << " ";
    }
     */

    
    
    // commence value trials
    cout << "Enter amount to test, or enter -1 to exit: ";
    int testVal;
    cin >> testVal;
    
    
    // repeat trials until user exits
    while(testVal >= 0){
        coinTest.greedy(testVal);
        coinTest.printGreedy();
        coinTest.optimal(testVal);
        coinTest.printOptimal();
        coinTest.compare();
        
        /*
        // Greedy algorithm
        int greed = testVal;
        int index = numC - 1;
        int coinsCounter = 0;
        int tempVal;
        string coinsUsed = "";
        
        // subtract largest coin value possible at every step
        while(greed > 0){
            tempVal = values[index];
            if (greed >= tempVal){
                greed -= tempVal;
                coinsUsed.append(to_string(tempVal) + " "); // record coins
                coinsCounter++; // count coins
            }else{
                index--;
                if (index < 0){
                    break;
                }
            }
        }
        
        // dynamic programming
        
        // report greedy algorithm results
        cout << "   Greedy: " << coinsUsed << endl;
        cout << "    Number of coins: " << coinsCounter << endl;
        
        // report dynamic programming results
        
        // report whether greed is optimal
        */
        // repeat or exit based on user input
        cout << "Enter amount to test, or enter -1 to exit: ";
        cin >> testVal;
    }
    
    cout << "Thank you for playing!" << endl;
    
    //delete[] values;
    return 0;
}
