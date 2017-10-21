//
//  main.cpp
//  Program3
//
//  Created by Jiang, Yangzi on 10/21/17.
//  Copyright © 2017 Jiang, Yangzi. All rights reserved.
//

#include <iostream>
#include <limits>

using namespace std;

int main() {
    
    int numM;
    cout << "Number of Matrices? ";
    cin >> numM;
    
    while (numM < 2){
        cout << "Need at least 2 Matrices to perform multiplication: ";
        cin >> numM;
    }
    
    int* dim = new int[numM + 1];
    
    cout << "Dimensions of matrix 1: ";
    cin >> dim[0] >> dim[1];
    
    for (int i = 2; i < numM + 1; i++){
        cout << "Dimensions of matrix " << i << ": " << dim[i-1] << " X ";
        cin >> dim[i];
    }
    
    for (int i = 0; i < numM + 1; i++){
        cout << dim[i] << endl;
    }
    
    // declare dynamic programming tables
    int* m = new int[numM * numM]; // multiplication table
    int* s = new int[numM * numM]; // best multiplication location table
    
    // initialize diagonal of m to zero
    for(int i = 0; i < numM; i++){
        m[i * numM + i] = 0;
    }
    
    // solve for best way to multiply set of matrices together
    int j, q, counter;
    for(int l = 0; l < numM - 1; l++){ // ????
        for(int i = 0; i < numM - l; i++){ // IF WRONG - LIMITS?
            j = i + l;
            m[i * numM + j] = numeric_limits<int>::max();
            for(int k = i; k < j - 1; k++){
                q = m[i * numM + k] + m[(k + 1) * numM + j] + dim[i - 1] * dim[k] * dim[j];
                if(q < m[i * numM + j]){
                    m[i * numM + j] = q;
                    s[i * numM + j] = k;
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
