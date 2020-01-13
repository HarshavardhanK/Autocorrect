//
//  bk-tree-gfg.cpp
//  Autocorrect
//
//  Created by Harshavardhan K on 12/01/20.
//  Copyright © 2020 Harshavardhan K. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int edit_distance(string str1, string str2) {
    
    int dp[str1.length() + 1][str2.length() + 1];

    for (int i = 0; i <= str1.length(); i++) {
        
        for (int j = 0; j <= str2.length(); j++) {
            
            if (i == 0)
                dp[i][j] = j;
  
            else if (j == 0)
                dp[i][j] = i; // Min. operations = i
  
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
  
            else
                dp[i][j] = 1 + min(dp[i][j-1],  // Insert
                                   min(dp[i-1][j],  // Remove
                                   dp[i-1][j-1])); // Replace
        }
    }
  
    return dp[str1.length()][str2.length()];
}

#define MAXN 100
#define TOL 2
#define LEN 10

struct Node {
    
    std::string word;
    
    int next[2 * LEN];
    
    Node(std::string str): word(str) {
        
        for(int i = 0; i < 2 * LEN; i++) {
            next[i] = 0;
        }
    }
    
    Node() {
        word = "";
    }
};

Node root;
Node tree[MAXN];

int ptr;

void add(Node& root, Node& curr) {
    
    if(root.word == "") {
        root = curr;
        return;
    }
    
    int dist = edit_distance(root.word, curr.word);
    
    if(tree[root.next[dist]].word == "") {
        
        ptr++;
        
        tree[ptr] = curr;
        
        root.next[dist] = ptr;
        
    } else {
        add(tree[root.next[dist]], curr);
    }
    
}

void test_tree() {
    
    std::vector<std::string> dict {"hell","help","shel","smell",
        "fell","felt","oops","pop","oouch"};
    
    ptr = 0;
    
    for(auto x: dict) {
        Node node = Node(x);
        add(root, node);
    }
    
    for(int i = 0; i < dict.size(); i++) {
        std::cout << tree[i].word << " ";
    }
    
    std::cout << '\n';
}

vector<string> get_similar_words(Node& root, string& str) {
    
    vector<string> similar_words;
    
    if(root.word == "") {
        return similar_words;
    }
    
    int dist = edit_distance(root.word, str);
    
    if(dist <= TOL) {
        similar_words.push_back(root.word);
    }
    
    int start = dist - TOL;
    
    if(start < 0) {
        start = 1;
    }
    
    while(start < dist + TOL) {
        vector<string> temp = get_similar_words(tree[root.next[start]], str);
        
        for(auto x: temp) {
            similar_words.push_back(x);
        }
        
        start++;
    }
    
    return similar_words;

}

void test() {
    
    std::vector<std::string> dict {"hell","help","shel","smell",
        "fell","felt","oops","pop","oouch"};
    
    ptr = 0;
    
    for(auto x: dict) {
        Node node = Node(x);
        add(root, node);
    }
    
    for(int i = 0; i < dict.size(); i++) {
        std::cout << tree[i].word << " ";
    }
    
    string str1 = "ops";
    string str2 = "helt";
    
    vector<string> match = get_similar_words(root, str1);
    
    for(auto x: match) {
        cout << x << '\n';
    }
    
    std::cout << '\n';
    
    
}
