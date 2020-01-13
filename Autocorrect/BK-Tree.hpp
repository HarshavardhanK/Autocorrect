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

#include "utilities.hpp"

using namespace std;

class BKNode {
    
    string word;
    
    int LENGTH = 20;
    
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
    
    BK_Tree(string root_word) {
        
        size = 0;
        
        root = new BKNode(root_word);
        pointer = 0;
        
        for(int i = 0; i < 200; i++) {
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

#endif /* BK_Tree_hpp */
