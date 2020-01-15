//
//  Runner.hpp
//  Autocorrect
//
//  Created by Harshavardhan K on 14/01/20.
//  Copyright © 2020 Harshavardhan K. All rights reserved.
//

#ifndef Runner_hpp
#define Runner_hpp

#include <iostream>
#include <thread>

#include "BK-Tree.hpp"
#include "Feed.hpp"

class Runner {
    
public:
    
    BK_Tree* tree;
    
    Runner(BK_Tree* tree) {
        this->tree = tree;
    }
    
    void operator() (string word) {
        tree->get_similar_words(word);
    }
    
};

class Driver {
    
    Feed_Data feed;
    
    std::vector<Runner*> runners;
    
public:
    
    void auto_correct(std::string&);
    void auto_correct_for(std::string&, char);
    
};

void Driver::auto_correct_for(std::string &word, char charac) {
    
    feed.generate_vector_for_charac(charac);
    
    std::vector<std::string> similar_words;
    
    Runner* run = new Runner(feed.get_vocabulary()[0]);
    
    thread thr(*run, word);
    
    thr.join();
    
    similar_words = run->tree->get_similarity_list();
    
    print_vector(similar_words);
}

void Driver::auto_correct(std::string &word) {
    
    feed.generate_vector_for_all();
    
    
    std::vector<std::vector<std::string>> similar_words;
    
    std::vector<BK_Tree*> vocabulary = feed.get_vocabulary();
    std::vector<thread> threads;
    
    for(int i = 'a'; i <= 'z'; i++) {
        
        Runner *run = new Runner(vocabulary[i - 'a']);
        
        //thread thread_runner(*run, word);
        threads.push_back(std::thread(*run, word));
        
        similar_words.push_back(run->tree->get_similarity_list());
        
    }
    
    for(auto&& thr: threads) {
        thr.join();
    }
    
    for(auto& list: similar_words) {
        print_vector(list);
        std::cout << '\n';
    }
    
    std::cout << '\n';
    
}

void test_runner() {
    
    BK_Tree* tree = new BK_Tree("hello");
    BK_Tree* tree2 = new BK_Tree("india");
    
    vector<string> words {"hello", "help", "hell", "shell", "pelt", "felt"};
    vector<string> words1 {"australia", "africa", "kenya", "egypt", "nairobi", "bangalore"};
    
    for(auto x: words) {
        tree->add_node(new BKNode(x));
    }
    
    for(auto x: words1) {
        tree2->add_node(new BKNode(x));
    }
    
    string word1 = "zuckerberg";
    string word2 = "ausstralia";
    
    Runner *run = new Runner(tree);
    Runner *run2 = new Runner(tree2);
    
    thread th1(*run, word1);
    thread th2(*run2, word2);
    
    th1.join();
    th2.join();
    
    cout << "Similarity list1\n";
    
    vector<string> sim1 = tree->get_similarity_list();
    
    cout << "Similarity list2\n";
    vector<string> sim2 = tree2->get_similarity_list();
    
    cout << "Sim2 sizze: " << sim2.size() << '\n';
    
    print_vector(sim1);
    print_vector(sim2);
}

#endif /* Runner_hpp */
