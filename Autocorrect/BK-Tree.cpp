//
//  BK-Tree.cpp
//  Autocorrect
//
//  Created by Harshavardhan K on 12/01/20.
//  Copyright © 2020 Harshavardhan K. All rights reserved.
//

#include "BK-Tree.hpp"


const int BKNode::edit_distance(BKNode* toNode) const {
    
    string node2_str = toNode->get_word();
    
    int store[word.length() + 1][node2_str.length() + 1];
    
    for(int i = 0; i <= word.length(); i++) {
        
        for(int j = 0; j <= node2_str.length(); j++) {
            
            if(i == 0) {
                store[i][j] = j;
                
            } else if(j == 0) {
                store[i][j] = i;
            
            
            } else if(node2_str[j - 1] == word[i - 1]) {
                store[i][j] = store[i - 1][j - 1];
                
            } else {
                
                store[i][j] = 1 + min(store[i - 1][j - 1], min(store[i - 1][j], store[i][j - 1]));
            }
            
        }
        
    }
    
    return store[word.length()][node2_str.length()];
}

void BK_Tree::add_node_helper(BKNode * root, BKNode * current) {
    
    if(root->get_word() == "") {
        root = current;
        return;
    }
    
    int distance = root->edit_distance(current);
    
   // cout << distance << '\n';
    
    if(tree[root->get_next_word_list()[distance]]->get_word() == "") {
        
        pointer++;
        
        tree[pointer] = current;
        
        root->get_next_word_list()[distance] = pointer;
        
    } else {
        
        add_node_helper(tree[root->get_next_word_list()[distance]], current);
    }
}

void BK_Tree::add_node(BKNode * current) {
    size++;
    add_node_helper(root, current);
}


void BK_Tree::print_tree() {
    
    for(int i = 0; i < size; i++) {
        cout << tree[i]->get_word() << '\n';
    }
    
    cout << '\n';
}

void test_tree() {
    
    BK_Tree* tree = new BK_Tree("hello");
    
    vector<string> words {"hello", "help", "hell", "shell", "pelt", "felt"};
    
    for(auto x: words) {
        tree->add_node(new BKNode(x));
    }
    
    tree->print_tree();
}
