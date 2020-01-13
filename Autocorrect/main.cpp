//
//  main.cpp
//  Autocorrect
//
//  Created by Harshavardhan K on 12/01/20.
//  Copyright © 2020 Harshavardhan K. All rights reserved.
//

#include <iostream>
#include "BK-Tree.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    BKNode* node1 = new BKNode("hel");
    BKNode* node2 = new BKNode("help");
    
    cout << node1->edit_distance(node2) << '\n';
    return 0;
}
