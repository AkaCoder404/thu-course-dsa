#include "stdio.h"
#include "stdint.h"
#include <vector>
#include <stack>



void method_1(std::stack<long int> &s, std::vector<long int> &s_out, int m) {
    // keep track of the current largest 
    std::stack<long int> track_stack;
    for (int i = 0; i < m; i++) {
        // std::cout << i << "\n";
        int p;
        long int x;
        scanf("%d", &p);
       
        if (p == 1) {
            scanf("%ld", &x);
            s.push(x);

            // first element
            if (s.size() == 1) {
                track_stack.push(x);
            }
            // if x larger, update track_stack
            else if (x > track_stack.top()) {
                track_stack.push(x);
            } 
            else track_stack.push(track_stack.top()); 

            s_out.push_back(track_stack.top());
        }
        else if (p == 2) {
            // if empty, no operation 
            if(!s.empty()) {
                s.pop();
                track_stack.pop();
                if(s.empty()) s_out.push_back(-1);   
                // if not empty, print the largest
                else s_out.push_back(track_stack.top());
            }
            else s_out.push_back(-1);
                   
        }
    }
}

int main() {
    int m;
    scanf("%d", &m);

    std::stack<long  int> s;
    std::vector<long int> s_out;

    // method 1: use stack and track largest using stack
    method_1(s, s_out, m);

    // print results
    for(int i = 0; i < s_out.size(); i++) {
        printf("%ld\n", s_out[i]);
    }
}



