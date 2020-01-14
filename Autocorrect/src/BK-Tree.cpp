//
//  BK-Tree.cpp
//  Autocorrect
//
//  Created by Harshavardhan K on 12/01/20.
//  Copyright © 2020 Harshavardhan K. All rights reserved.
//

#include "BK-Tree.hpp"

void BKNode::distance_to_next_word_list(int distance, int value) {
    
    vector<int>::iterator iter = next_word_list.begin();
    advance(iter, distance);
    
    next_word_list.insert(iter, value);
}

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
        
        root->distance_to_next_word_list(distance, pointer);
        
    } else {
        
        add_node_helper(tree[root->get_next_word_list()[distance]], current);
    }
}

void BK_Tree::add_node(BKNode * current) {
    size++;
    add_node_helper(root, current);
}

vector<string> BK_Tree::get_similar_words_helper(BKNode* root_, const string & word) {
     
    vector<string> similar_words_;
    
    if(root_->get_word() == "") {
        return similar_words_;
    }
    
    cout << "Examined word: " << root_->get_word() << '\n';
    
    int distance = root_->edit_distance(new BKNode(word));
    
    cout << "Distance is: " << distance << '\n';
    
    //print_vector(root_->get_next_word_list());
    
    if(distance <= TOLERANCE) {
        similar_words_.push_back(root_->get_word());
    }
    
    int start = distance - TOLERANCE;
    
    if(start < 0) {
        start = 1;
    }
    
    while(start < distance + TOLERANCE) {
        
        vector<string> temp = get_similar_words_helper(tree[root_->get_next_word_list()[start]], word);
        
        for(auto word_: temp) {
            similar_words_.push_back(word_);
        }
        
        start++;
    }
    
    return similar_words_;
}

vector<string> BK_Tree::get_similar_words(const string &word) {
    this->similar_words = get_similar_words_helper(this->root, word);
    
    return similar_words;
}

void BK_Tree::print_tree() {
    
    for(int i = 0; i < size; i++) {
        cout << tree[i]->get_word() << '\n';
    }
    
    cout << '\n';
}

void BK_Tree::print_similarity_list() {
    
    for(auto word: similar_words) {
        cout << word << endl;
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

void test_similarity() {
    
    BK_Tree* tree = new BK_Tree("hello");
    
    vector<string> words {"hello", "help", "hell", "shell", "pelt", "felt"};
    
    for(auto x: words) {
        tree->add_node(new BKNode(x));
    }
    
    string word = "pellt";
    
    tree->get_similar_words(word);
    
    cout << tree->get_similarity_list().size() << '\n';
    
    tree->print_similarity_list();
    
    
}
