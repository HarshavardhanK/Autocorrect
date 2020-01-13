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
    
    BKNode() {}
    
    const string get_word() { return word; }
    
    const int edit_distance(BKNode*) const;
    
    vector<int> get_next_word_list() {
        return next_word_list;
    }
};

class BK_Tree {
    
    BKNode* root;
    
    vector<BKNode*> tree;
    
    void add_node_helper(BKNode*, BKNode*);
    
    int pointer;
    
    static const int tree_size = 200;
    
    int size;
    
public:
    
    BK_Tree(string root_word) {
        
        size = 0;
        
        root = new BKNode(root_word);
        pointer = 0;
        
        for(int i = 0; i < 200; i++) {
            tree.push_back(new BKNode(""));
        }
    }
    
    void add_node(BKNode*);
    
    //Utility functions
    
    void print_tree();
    
    
};

void test_tree();

#endif /* BK_Tree_hpp */
