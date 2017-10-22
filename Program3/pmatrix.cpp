////////////////////////////////////////////////////////////////////////////////
//  pmatrix.cpp
//  Program file implementing solution to Program 3: Dynamic Duo
//
//  Yangzi Jiangon, Collin Epstein
//  10/26/17
//  CSC321
//  Dr. Mossinghoff
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main() {
    
    // get program parameters from user
    // get # of matrices
    int numM;
    cout << "Number of Matrices? ";
    cin >> numM;
    
    // validate input
    while (numM < 2){
        cout << "Need at least 2 Matrices to perform multiplication: ";
        cin >> numM;
    }
    
    // get dimensions of matrices
    
    int* dim = new int[numM + 1];
    cout << "Dimensions of matrix 1: ";
    cin >> dim[0] >> dim[1];
    
    // validate input
    while(dim[0] < 1 || dim[1] < 0){
        cout << "Matrix dimension must be greater than zero: ";
        cin >> numM;
    }
    
    for (int i = 2; i < numM + 1; i++){
        cout << "Dimensions of matrix " << i << ": " << dim[i-1] << " X ";
        cin >> dim[i];
        
        // validate input
        while(dim[i] < 1){
            cout << "Matrix dimension must be greater than zero: ";
            cin >> numM;
        }
    }
    
    // declare dynamic programming tables
    int* m = new int[numM * numM]; // multiplication table
    int* s = new int[numM * numM]; // best multiplication location table
    
    // initialize all of m and s to zero
    for(int i = 0; i < numM; i++){
        for(int j = 0; j < numM; j++){
            m[i * numM + j] = 0;
            s[i * numM + j] = 0;
        }
    }
        
    
    // solve for best way to multiply set of matrices together
    int j, q, counter = 0;
    for(int l = 1; l < numM; l++){ // ????
        for(int i = 0; i < numM - l; i++){ // IF WRONG - LIMITS?
            j = i + l;
            m[i * numM + j] = numeric_limits<int>::max(); // approx. infinity
            for(int k = i; k < j; k++){
                q = m[i * numM + k] + m[(k + 1) * numM + j] + dim[i] * dim[k + 1] * dim[j + 1];
                if(q < m[i * numM + j]){
                    m[i * numM + j] = q;
                    s[i * numM + j] = k + 1;
                }
                counter++;
            }
        }
    }
    
    // print m table
    cout << "Table m[i,j]:" << endl;
    for(int i = 0; i < numM; i++){
        for(int j = 0; j < numM; j++){
            cout << m[i * numM + j] << " "; // <---- !!!!!
        }
        cout << endl;
    }
    cout << endl;
    
    // print s table
    cout << "Table s[i,j]:" << endl;
    for(int i = 0; i < numM; i++){
        for(int j = 0; j < numM; j++){
            cout << s[i * numM + j] << " "; // <---- !!!!!
        }
        cout << endl;
    }
    cout << endl;
    
    // print optimal grouping
    // somehow
    
    // print total cost
    cout << "Total Cost: " << m[numM - 1] << " multiplications." << endl;
    
    // print inner loop running
    cout << "Inner loop run count: " << counter << endl;
    
    // clean up
    delete[] m;
    delete[] s;
    delete[] dim;
    
    return 0;
}
