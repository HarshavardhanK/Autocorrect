//
//  Feed.cpp
//  Autocorrect
//
//  Created by Harshavardhan K on 15/01/20.
//  Copyright © 2020 Harshavardhan K. All rights reserved.
//

#include "Feed.hpp"

std::vector<std::string> Feed_Data::generate_vector_for(char charac) {
    
    std::string character_path = PARENT_PATH + std::string(1, charac) + ".txt";
    
    std::ifstream file;
    file.open(character_path);
    
    std::vector<std::string> word_list;
    
    while(file) {
        
        std::string word;
        
        getline(file, word);
        
        word_list.push_back(word);
    }
    
    return word_list;
}

BK_Tree* Feed_Data::generate_tree_for(char charac) {
    
    std::vector<std::string> words_list = generate_vector_for(charac);
    
    BK_Tree* tree = new BK_Tree(words_list[0], (int) words_list.size());
    
    std::cout << "Size of vector for char " << charac << " is " << words_list.size() << '\n';
    
    for(int i = 1; i < words_list.size(); i++) {
        tree->add_node(new BKNode(words_list[i]));
    }
    
    return tree;
}

void Feed_Data::generate_vector_for_all() {
    
    std::vector<BK_Tree*> all_vect;
    
    for(int i = 'a'; i <= 'z'; i++) {
        all_vect.push_back(generate_tree_for(i));
    }
    
    std::cout << "Generated trees for all characters in the alphabet\n";
    
    this->vocabulary = all_vect;
}

void Feed_Data::generate_vector_for_charac(char charac) {
    
    std::vector<BK_Tree*> all_vect;
    
    all_vect.push_back(generate_tree_for(charac));
    
    this->vocabulary = all_vect;
    
}

void test_feed(char charac) {
    
    Feed_Data feed;
    
    std::vector<std::string> vect = feed.generate_vector_for(charac);
    
    std::cout << "Size of vector is: " << vect.size() << '\n';

    for(int i = 0; i < 10; i++) {
        std::cout << vect[i] << '\n';
    }

    std::cout << '\n';
    
    BK_Tree* tree = feed.generate_tree_for('e');
    BK_Tree* tree2 = feed.generate_tree_for('a');
    
    //tree2->print_tree();
    //tree->print_tree();
    
}

void test_all() {
    
    Feed_Data feed;
    feed.generate_vector_for_all();
    
    std::vector<BK_Tree*> all_vect = feed.get_vocabulary();
    all_vect[0]->print_tree();
}
