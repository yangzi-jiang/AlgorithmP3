////////////////////////////////////////////////////////////////////////////////
//  change.cpp
//  Program file implementing solution to Program 3: Dynamic Duo.
//  Solution to making change.
//
//  Yangzi Jiangon, Collin Epstein
//  10/26/17
//  CSC321
//  Dr. Mossinghoff
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <iostream>
#include "coins.h"

using namespace std;

int main(){
    int numC;
    
    cout << "Number of coins bigger than one cent? ";
    cin >> numC;
    cout << endl;
    cout << "Enter the values of the these coins in increasing order." << endl;
    
    cout << "   Coin Value 1: 1" << endl;
    
    int* values = new int[++numC];
    
    values[0] = 1;
    
    for (int i = 1; i < numC; i++){
        cout << "   Coin value " << i + 1 << ": ";
        cin >> values[i];
    }
    
    for (int i = 0; i < numC; i++){
        cout << values[i] << " ";
    }
    
    int testVal;
    
    cout << "Enter amount to test, or enter -1 to exit: ";
    cin >> testVal;
    
    // code
    while(testVal >= 0){
        
        //Greed
        int greed = testVal;
        int index = numC - 1;
        string coinsUsed = "";
        int coinsCounter = 0;
        
        while(greed > 0){
            
            if (greed >= values[index]){
                greed -= values[index];
                coinsUsed.append(to_string(values[index]) + " ");
                coinsCounter++;
            }
            
            else{
                index--;
                
                if (index < 0){
                    break;
                }
            }
        }
        
        cout << "   Greedy: " << coinsUsed << endl;
        cout << "    Number of coins: " << coinsCounter << endl;
        
        
        
        
        
        cout << "Enter amount to test, or enter -1 to exit: ";
        cin >> testVal;
    }
    
    cout << "Thank you for playing!" << endl;
    
    delete[] values;
    return 0;
}
