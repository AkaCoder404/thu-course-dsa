#include "stdio.h"
#include <queue>
#include <vector>
#include <stack>

void method_1(std::stack<std::pair<long int, long int> > &s, std::vector<long int> &v_out, int m) {
    // keep track of the deque stack
    std::stack<std::pair<long int, long int> > dequeue_stack;
    for (int i = 0; i < m; i++) {
        int p;
        long int x;
        scanf("%d", &p);

        if (p == 1) {
            scanf("%ld", &x); 

            // first enqueue
            if (s.empty()) s.push({x, x});            
            else if (x > s.top().second) {
                s.push({x, x});
            } else s.push({x, s.top().second});

            // max value of enqueue and dequeue stacks
            long int max_value = 0;
            if (!s.empty() && !dequeue_stack.empty()) max_value = s.top().second > dequeue_stack.top().second ? s.top().second : dequeue_stack.top().second;
            else if (!s.empty() && dequeue_stack.empty()) max_value = s.top().second;
            else if (s.empty() && !dequeue_stack.empty()) max_value = dequeue_stack.top().second; 
            v_out.push_back(max_value);
        }
        else if(p == 2) {
            // if either is not empty
            if (!dequeue_stack.empty() || !s.empty()) {
                // if dequeue stack is empty and enqueue is not
                if(!s.empty() && dequeue_stack.empty()) {
                    // pop all enqueue stack to dequeue
                    while(!s.empty()) {
                        if(dequeue_stack.size() == 0) {
                            dequeue_stack.push({s.top().first, s.top().first});
                            s.pop();
                        }
                        else {
                            if (s.top().first > dequeue_stack.top().second) {
                                dequeue_stack.push({s.top().first, s.top().first});
                            }
                            else dequeue_stack.push({s.top().first, dequeue_stack.top().second});
                            s.pop();
                        }
                    }
                   
                    dequeue_stack.pop();
                    if(dequeue_stack.empty() && s.empty()) v_out.push_back(-1); 
                    else  v_out.push_back(dequeue_stack.top().second); 
                }
                // if dequeue stack is not empty
                else if(!dequeue_stack.empty()) {
                    // max value of enqueue and dequeue
                    dequeue_stack.pop();
                    if (dequeue_stack.empty() && s.empty()) v_out.push_back(-1); 
                    else {
                        long int max_value;
                        if (!s.empty() && !dequeue_stack.empty()) max_value = s.top().second > dequeue_stack.top().second ? s.top().second : dequeue_stack.top().second;
                        else if (!dequeue_stack.empty()) max_value = dequeue_stack.top().second; 
                        else if (dequeue_stack.empty() && !s.empty()) max_value = s.top().second;
                        v_out.push_back(max_value);
                    }
                }                
            } 
            // if both arrays are empty
            else v_out.push_back(-1);
        }
    }
}

int main() {
    int m;
    scanf("%d", &m);

    std::stack<std::pair<long int, long int> > s;
    // std::queue<long int> q;
    std::vector<long int> v_out;

    // method 1: use queue naive search method for largest
    method_1(s, v_out, m);

    // print results
    for(int i = 0; i < v_out.size(); i++) {
        printf("%ld\n", v_out[i]);
    }
    
}