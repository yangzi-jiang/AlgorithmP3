////////////////////////////////////////////////////////////////////////////////
//  coins.cpp
//  Program file implementing solution to Program 3: Dynamic Duo.
//  Implementation file for coins class for making change.
//
//  Yangzi Jiangon, Collin Epstein
//  10/26/17
//  CSC321
//  Dr. Mossinghoff
////////////////////////////////////////////////////////////////////////////////

#include "coins.h"

// constructor
Coins::Coins() : numCoins(0), values(NULL), tableSize(0), coinCounts(NULL),
coinsUsed(""), countGreedy(0), countOptimal(0){
    
    // instantiate coins counts array, all values = 0
    //coinCounts = new int[size * size];
    //for(int i = 0; i < size; i++){
    //    for(int j = 0; j < size; j++) coinCounts[i * size + j] = 0;
    //}
}

// destructor
Coins::~Coins(){
    delete [] values;
    delete [] coinCounts;
}

// dynamically resize array fields
void Coins::resize(int cents){
    
    if(cents > tableSize){
        // allocate new array and copy over old values
        int* temp = new int[cents * cents];
        for(int i = 0; i < cents; i++){
            for(int j = 0; j < cents; j++){
                if(i < tableSize && j < tableSize){
                    temp[i * cents + j] = coinCounts[i * cents + j];
                }else{
                    temp[i * cents + j] = 0;
                }
            }
        }
        
        // delete old array, update pointers and size value
        delete [] coinCounts;
        coinCounts = temp;
        tableSize = cents;
    }
}

void Coins::initializeTrial(){
    // determine number of coins from user input
    cout << "Number of coins bigger than one cent? ";
    cin >> numCoins;
    
    // input validation
    while(numCoins < 1){
        cout << "Must use at least one coint: ";
        cin >> numCoins;
    }
    cout << endl;
    
    values = new int[++numCoins]; // allocate coin values array
    
    // determine coin values from user input
    cout << "Enter the values of the these coins in increasing order." << endl;
    cout << "   Coin Value 1: 1" << endl; // always use penny, guarantee result
    values[0] = 1;
    
    for (int i = 1; i < numCoins; i++){
        cout << "   Coin value " << i + 1 << ": ";
        cin >> values[i];
        
        // input validation
        while(values[i] < 2){
            cout << "    Each coin must have a value greater than one: ";
            cin >> values[i];
        }
    }
    
    // Need sort??????????????????????????????????????????????????????????
    
    cout << endl;
}

void Coins::greedy(int trial){
    
    int index = numCoins - 1;
    countGreedy = 0;
    int tempVal;
    coinsUsed.clear();
    
    // subtract largest coin value possible at every step
    while(trial > 0){
        tempVal = values[index];
        
        if (trial >= tempVal){
            trial -= tempVal;
            coinsUsed.append(to_string(tempVal) + " "); // record coins
            countGreedy++; // count coins
        }
        
        else{
            index--;
            if (index < 0){
                break;
            }
        }
    }
    
}

void Coins::printGreedy(){
    // report greedy algorithm results
    cout << "   Greedy: " << coinsUsed << endl;
    cout << "    Number of coins: " << countGreedy << endl;
    coinsUsed.clear();
}

void Coins::optimal(int trial){
    
    countOptimal = 0;
    
    coinsUsed.clear();
    
    string* storedValues = new string[trial];
    
    //    while (trial >= values[numCoins - 1]){
    //        trial -= values[numCoins - 1];
    //        coinsUsed.append(to_string(tempVal) + " ");
    //        countOptimal++;
    //    }
    
    // store the coins needed for each value
    storedValues[0] = to_string(values[0]) + " ";
    coinsUsed = "1 ";
    
    int coinsTaken = 1; // How many different kind of coins we considered
    int tempVal;
    
    for(int i = 2; i <= trial; i++){
        tempVal = i;
        
        // Check if a coin equals to the current test value
        if (tempVal == values[coinsTaken]){
            coinsUsed = values[coinsTaken];
            storedValues[i - 1] = coinsUsed;
            countOptimal = 1;
            cout << values[coinsTaken] << endl;
            cout << storedValues[i - 1] << endl;
            coinsTaken++;
        }
        else{
            if (tempVal > values[coinsTaken - 1]){
                for (int j = 0; j < tempVal - values[coinsTaken - 1]; j++){
                    // record
                    coinsUsed = storedValues[i - 2];
                    coinsUsed.append(to_string(values[coinsTaken - 1]) + " ");
                    countOptimal++; // count coins
                }
            }
            storedValues[i - 1] = coinsUsed;
        }
    }
    storedValues[trial - 1] = coinsUsed;
}

void Coins::printOptimal(){
    cout << "   Optimal: " << coinsUsed << endl;
    cout << "    Number of Coins: " << countOptimal << endl;
    coinsUsed.clear();
}

void Coins::topDown(int value){
    topDownHelper(value, 0, tableSize - 1);
}

void Coins::topDownHelper(int value, const int index1, const int index2){
    
    //for(int i = 0; i < )
}

void Coins::compare(){
    
    if (countGreedy == countOptimal){
        cout << "   Greed is optimal!" <<endl;
    }
    
    else{
        cout << "   Greed is not optimal!" <<endl;
    }
}
