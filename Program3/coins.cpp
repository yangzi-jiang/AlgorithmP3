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
Coins::Coins() : numCoins(0), values(NULL), coinsUsed(""), countGreedy(0),
                 countOptimal(0), tableSize(0), coinCounts(NULL),
                 optimalCoins(NULL) {}

// destructor
Coins::~Coins(){
    delete [] values;
    delete [] coinCounts;
    delete [] optimalCoins;
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
    cout << "   Coin Value 1: 1" << endl;
    values[0] = 1; // always use penny, guarantees result
    
    for (int i = 1; i < numCoins; i++){
        cout << "   Coin value " << i + 1 << ": ";
        cin >> values[i];
        
        // input validation
        while(values[i] < 2){
            cout << "    Each coin must have a value greater than one: ";
            cin >> values[i];
        }
    }
    
    // sort coin values, to ensure proper algorithm execution
    sort(values, values + numCoins);
    //for(int i = 0; i < numCoins; i++) cout << values[i] << " "; // check sort
    cout << endl;
}

// find solution using greedy algorithm
void Coins::greedy(int trial){
    
    // (re)set counters
    int index = numCoins - 1;
    int tempVal;
    countGreedy = 0;
    coinsUsed.clear();
    
    // subtract largest coin value possible at every step
    while(trial > 0){
        tempVal = values[index];
        if (trial >= tempVal){
            trial -= tempVal;
            coinsUsed.append(to_string(tempVal) + " "); // record coins
            countGreedy++; // count coins
        }else{
            index--;
            if (index < 0){
                break;
            }
        }
    }
    
}

// report greedy algorithm results
void Coins::printGreedy(){
    cout << "   Greedy: " << coinsUsed << endl;
    cout << "    Number of coins: " << countGreedy << endl;
    coinsUsed.clear();
}

// use dynamic programming to find optimal result
void Coins::optimal(const int trial){
    
    // initialize array with new size (if necessary)
    resize(trial + 1);
    
    // build solutions from bottom up - smallest subvalues first
    for(int i = 1; i <= trial; i++){
        // check using coins from smallest to largest
        for(int j = 0; j < numCoins; j++){
            // current coins is less than subproblem value
            if(values[j] <= i){
                // check result of subproblem value - current coin value
                int subvalue = coinCounts[i - values[j]];
                // save result if it is optimal thus far
                if(subvalue != INT_MAX && subvalue + 1 < coinCounts[i]){
                    coinCounts[i] = subvalue + 1;
                    optimalCoins[i] = optimalCoins[i - values[j]] + " "
                        + to_string(values[j]);
                }
            }
        }
    }
    
    // save results
    countOptimal = coinCounts[trial];
    coinsUsed = optimalCoins[trial];
}

// print dynamic programming results
void Coins::printOptimal(){
    cout << "   Optimal: " << coinsUsed << endl;
    cout << "    Number of Coins: " << countOptimal << endl;
    coinsUsed.clear();
}

// compare coin counts for both methodsm reports whether greed is optimal
void Coins::compare(){
    
    if (countGreedy == countOptimal){
        cout << "   Greed is optimal!" <<endl;
    }
    else{
        cout << "   Greed is not optimal!" <<endl;
    }
}

// dynamically resize array fields
void Coins::resize(const int cents){
    
    // only reallocate if necessary
    if(cents > tableSize){
        // allocate new array and copy over old values
        int* tempInt = new int[cents];
        string* tempStr = new string[cents];
        for(int i = 1; i < cents; i++){
            if(i < tableSize){
                tempInt[i] = coinCounts[i];
                tempStr[i] = optimalCoins[i];
            }else{
                tempInt[i] = INT_MAX; // approximate infinity
                tempStr[i] = "";
            }
        }
        
        // delete old array, update pointers and size value
        delete [] coinCounts;
        delete [] optimalCoins;
        coinCounts = tempInt;
        optimalCoins = tempStr;
        tableSize = cents;
    }
}
