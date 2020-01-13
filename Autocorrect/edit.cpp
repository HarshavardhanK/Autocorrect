#include <iostream>
using namespace std;

int edit_distance(string str1, string str2) {

    int store[str1.length() + 1][str2.length() + 1];

    for(int i = 0; i <= str1.length(); i++) {

        for(int j = 0; j <= str2.length(); j++) {

            if(i == 0) {
                store[i][j] = j;

            } else if(j == 0) {
                store[i][j] = i;
            }

            if(str1[i - 1] == str2[j - 1]) {
                store[i][j] = store[i - 1][j - 1];

            } else {
                store[i][j] = 1 + min(store[i - 1][j - 1], min(store[i][j - 1], store[i - 1][j]));
            }

        }
    }

    return store[str1.length()][str2.length()];
}

int editDistDP(string str1, string str2) { 
    
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

int main() {

    cout << editDistDP("hello", "help") << '\n';

    return 0;
}