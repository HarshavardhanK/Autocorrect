//
//  utilities.hpp
//  Autocorrect
//
//  Created by Harshavardhan K on 13/01/20.
//  Copyright © 2020 Harshavardhan K. All rights reserved.
//

#ifndef utilities_hpp
#define utilities_hpp

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print_vector(vector<T> vect) {
    
    for(auto x: vect) {
        cout << x << '\n';
    }
        
        cout << '\n';
}

#endif /* utilities_hpp */
