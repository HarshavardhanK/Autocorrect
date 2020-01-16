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

void print_vector(std::vector<T> vect) {
    
    for(auto x: vect) {
        std::cout << x << '\n';
    }
        
        std::cout << '\n';
}




#endif /* utilities_hpp */
