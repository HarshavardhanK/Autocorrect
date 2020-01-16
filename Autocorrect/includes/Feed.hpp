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

class Feed_Data {
    
    const std::string PARENT_PATH = "/Users/harshavardhank/Desktop/Code/DSA/Autocorrect/Autocorrect/data/";
    const std::string HALVED_PARENT_PATH = "/Users/harshavardhank/Desktop/Code/DSA/Autocorrect/Autocorrect/data/halved/";

    
    std::vector<BK_Tree*> vocabulary;
    
public:
    
    std::vector<std::string> generate_vector_for(char charac);
    void generate_vector_for_all();
    void generate_vector_for_charac(char charac);
    BK_Tree* generate_tree_for(char charac);
    
    const std::vector<BK_Tree*> get_vocabulary() {
        return vocabulary;
    }
    
    //SPLIT APPROACH FOR BOOSTED EFFICIENCY ON MULTHITHREADED SYSTEMS
    //Scales to multiple threads (currently at two)
    
    void split_generate_vectors_for_charac(char);
    std::vector<std::vector<std::string>> split_generate_vector_for(char charac, int);
    std::vector<BK_Tree*> split_generate_tree_for_charc(char);
    
};

std::vector<std::string> load_file(std::string);

void test_split_generate();
void test_feed(char);
void test_all();

#endif /* file_handling_h */
