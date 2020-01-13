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
    
    vector<int> next_word_list;
    
public:
    
    BKNode(string word) {
        this->word = word;
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
    
public:
    
    BK_Tree(string root_word) {
        
        root = new BKNode(root_word);
        
    }
    
    void add_node(BKNode*);
    
    //Utility functions
    
    void print_tree();
    
    
};

#endif /* BK_Tree_hpp */
