#include "stdio.h"
#include <string>
#include <iostream>
#include <vector>



// without kmp
void method_1(std::vector<int> &v_out, std::string &s) {
    for(int i = 0; i < s.length(); i++) {
        int max = 0;
        for(int j = 0; j <= i; j++) {
            if(s.substr(0, j) == s.substr(i - j + 1, j)) {
                max = j;
            }
        }
        // printf("%d\n", max);
        v_out.push_back(max);
    } 
}

int longestPrefixSuffix(std::string s)
{
    int n = s.length();
    
    // longest prefix
    int lps[n];
    lps[0] = 0;  
    // length of the previous, longest prefix suffix
    int len = 0;
 
    // the loop calculates lps[i] for i = 1 to n-1
    int i = 1;
    while (i < n) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            // (pat[i] != pat[len]) 
            if (len != 0){
                len = lps[len-1];
            }
            else {// if (len == 0) 
                lps[i] = 0;
                i++;
            }
        }
    }
 
    int res = lps[n-1];
 
    // non overlaping parts
    return res;
  
}

void method_2(std::vector<int> &v_out, std::string &s) {
    for(int i = 1; i < s.length() + 1; i++) {
        // store text
        std::string T = s.substr(0, i);
        // std::cout << T << "\n";
        int val = longestPrefixSuffix(T);
        printf("%d\n", val);
        // v_out.push_back(val);   
    }
}

int main() {
    std::string s;
    std::cin >> s;
    
    std::vector<int> v_out;
   

    // method 1
    method_2(v_out, s);

    // method 2
    
    // print out results
    // for (int i = 0; i < v_out.size(); i++) {
    //     printf("%d\n", v_out[i]);
    // }
}