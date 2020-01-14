//
//  file_handling.h
//  Autocorrect
//
//  Created by Harshavardhan K on 15/01/20.
//  Copyright © 2020 Harshavardhan K. All rights reserved.
//

#ifndef file_handling_h
#define file_handling_h

#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>

#include "BK-Tree.hpp"

//namespace fs = std::filesystem;

class Feed_Data {
    
    const std::string PARENT_PATH = "/Users/harshavardhank/Desktop/Code/DSA/Autocorrect/Autocorrect/data/";
    
public:
    
    std::vector<std::string> generate_vector_for(char charac);
    BK_Tree* generate_tree_for(char charac);
    
};

void test_feed(char);


#endif /* file_handling_h */
