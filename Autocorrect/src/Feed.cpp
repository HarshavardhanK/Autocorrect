//
//  Feed.cpp
//  Autocorrect
//
//  Created by Harshavardhan K on 15/01/20.
//  Copyright © 2020 Harshavardhan K. All rights reserved.
//

#include "Feed.hpp"

//HELPER

std::vector<std::string> load_file(std::string path_name) {
    
    std::ifstream file;
    file.open(path_name);
    
    std::vector<std::string> word_list;
    
    while(file) {
        
        std::string word;
        
        getline(file, word);
        
        word_list.push_back(word);
    }
    
    return word_list;
}

std::vector<std::string> Feed_Data::generate_vector_for(char charac) {
    
    std::string character_path = PARENT_PATH + std::string(1, charac) + ".txt";
    
    return load_file(character_path);
    
}

//MARK:- SPLIT APPROACH

std::vector<std::vector<std::string>> Feed_Data::split_generate_vector_for(char charac, int splits) {
    
    std::vector<std::vector<std::string>> words_list;
    
    for(int i = 0; i < splits; i++) {
        std::string _PATH = HALVED_PARENT_PATH + std::string(1, charac) + to_string(i + 1) + ".txt";
        std::cout << _PATH <<  '\n';
        
        words_list.push_back(load_file(_PATH));
    }
    
    return words_list;
}

std::vector<BK_Tree*> Feed_Data::split_generate_tree_for_charc(char charac) {
    
    std::vector<std::vector<std::string>> words_list = split_generate_vector_for(charac, 2);
    std::vector<BK_Tree*> tree_vect;
    
    for(auto& vect: words_list) {
        
        BK_Tree* tree = new BK_Tree(vect[0], (int) vect.size());
        
        for(int i = 0; i < vect.size(); i++) {
            tree->add_node(new BKNode(vect[i]));
        }
        
        tree_vect.push_back(tree);
    }
    
    return tree_vect;
}

void Feed_Data::split_generate_vectors_for_charac(char charac) {
    this->vocabulary = split_generate_tree_for_charc(charac);
}



//MARK:- Single approach


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

void test_split_generate() {
    
    Feed_Data feed;
    //feed.split_generate_vector_for('a', 2);
    feed.split_generate_vectors_for_charac('m');
    
}

void test_all() {
    
    Feed_Data feed;
    feed.generate_vector_for_all();
    
    std::vector<BK_Tree*> all_vect = feed.get_vocabulary();
    all_vect[0]->print_tree();
}



//MARK:- PARSER

vector<string> Parser::string_to_vec(string word) {
    
    std::istringstream word_stream(word);
    std::vector<std::string> string_vec;
    
    do {
        
        std::string str;
        word_stream >> str;
        
        string_vec.push_back(str);
        
    } while(word_stream);
    
    return string_vec;
}

pair<string, int> Parser::get_word_frequency(string line) {
    
    stringstream word_stream(line);
    string data;
    
    pair<string, int> frequency;
    
    vector<string> items;
    
    while(getline(word_stream, data, ',')) {
        items.push_back(data);
    }
    
    frequency.first = items[0];
    frequency.second = stoi(items[1]);
    
    return frequency;
}

map<string, int> Parser::get_frequency_list(string PATH) {
    
    map<string, int> frequency_list;
    
    ifstream file;
    file.open(PATH, 'r');
    
    while(file) {
        
        string line;
        
        getline(file, line);
        
        frequency_list.insert(get_word_frequency(line));
    }
    
    return frequency_list;
}

