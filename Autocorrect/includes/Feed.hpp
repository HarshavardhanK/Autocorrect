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
    
    std::vector<BK_Tree*> vocabulary;
    
public:
    
    std::vector<std::string> generate_vector_for(char charac);
    void generate_vector_for_all();
    
    void generate_vector_for_charac(char charac);
    
    BK_Tree* generate_tree_for(char charac);
    
    const std::vector<BK_Tree*> get_vocabulary() {
        return vocabulary;
    }
    
};

void test_feed(char);
void test_all();

#endif /* file_handling_h */
