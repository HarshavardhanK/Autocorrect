//
//  main.cpp
//  Autocorrect
//
//  Created by Harshavardhan K on 12/01/20.
//  Copyright © 2020 Harshavardhan K. All rights reserved.
//

#include <iostream>
#include "../includes/Runner.hpp"

using namespace std;

void test_driver() {
    
    Driver driver;
    string word = "whta";
    driver.auto_correct_for(word);
}

void test_sentence() {
    
    Driver driver;
    
    std::string word;
    
    cout << "Enter sentence: ";
    getline(cin, word);
    
    vector<string> string_vec = string_to_vec(word);
    
    for(auto& str: string_vec) {
        driver.auto_correct_for(str);
    }
}

int main(int argc, const char * argv[]) {
    
    //test_driver();
    
    test_sentence();
    
    //test_split_generate();
    
    return 0;
}
