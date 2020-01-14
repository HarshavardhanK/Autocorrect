//
//  BK-Tree.hpp
//  Autocorrect
//
//  Created by Harshavardhan K on 12/01/20.
//  Copyright © 2020 Harshavardhan K. All rights reserved.
//

#ifndef BK_Tree_hpp
#define BK_Tree_hpp

#include <vector>
#include <iostream>

#include <thread>

#include "utilities.hpp"

using namespace std;

class BKNode {
    
    string word;
    
    int LENGTH = 50;
    
    vector<int> next_word_list;
    
public:
    
    BKNode(string word) {
        this->word = word;
        
        for(int i = 0; i < LENGTH; i++) {
            next_word_list.push_back(0);
        }
    }
    
    BKNode() {
        word = "";
    }
    
    const string get_word() { return word; }
    
    const int edit_distance(BKNode*) const;
    
    vector<int> get_next_word_list() {
        return next_word_list;
    }
    
    void distance_to_next_word_list(int distance, int value);
};

class BK_Tree {
    
    int size;
    int tree_capacity;
    int pointer;
    
    static const int tree_size = 200;
    static const int TOLERANCE = 4;
    
    BKNode* root;
    
    vector<BKNode*> tree;
    vector<string> similar_words;
    
    //Helper functions
    void add_node_helper(BKNode*, BKNode*);
    vector<string> get_similar_words_helper(BKNode*, const string&);
    
public:
    
    BK_Tree(string root_word, int capacity = 50) {
        
        size = 0;
        tree_capacity = capacity;
        
        root = new BKNode(root_word);
        pointer = 0;
        
        for(int i = 1; i < tree_capacity; i++) {
            tree.push_back(new BKNode(""));
        }
    
    }
    
    vector<string> get_similarity_list() {
        return similar_words;
    }
    
    void add_node(BKNode*);
    vector<string> get_similar_words(const string&);
    
    //Utility functions
    void print_similarity_list();
    void print_tree();
    
};

void test_tree();
void test_similarity();
void test_multithreading();

#endif /* BK_Tree_hpp */
