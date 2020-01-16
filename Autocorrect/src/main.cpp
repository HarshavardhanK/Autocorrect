//
//  main.cpp
//  Autocorrect
//
//  Created by Harshavardhan K on 12/01/20.
//  Copyright © 2020 Harshavardhan K. All rights reserved.
//

#include <iostream>
#include "../includes/BK-Tree.hpp"
#include "../includes/Runner.hpp"
#include "../includes/Feed.hpp"

using namespace std;

void test_driver() {
    
    Driver driver;
    string word = "whta";
    driver.auto_correct_for(word);
}

int main(int argc, const char * argv[]) {
    
    test_driver();
    
    //test_split_generate();
    
    return 0;
}
