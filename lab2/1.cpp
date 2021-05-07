#include "stdio.h"
#include <vector>

void method_1(int n, int m/* , std::vector<int> &v_out */) {

    // std::vector< std::vector<long int> > stacks;
    std::vector<int> *stacks = new std::vector<int>[n];

    for (int i = 0; i < m; i++) {
        int query; 
        int x, y;
        scanf("%d %ld %ld", &query, &x, &y);

        // sorting
        if (query == 1) {
         
            // initialize nth stack with value n
            if (stacks[x - 1].empty()) {
                stacks[x - 1].push_back(-1);
                stacks[x - 1].push_back(x);
            }

            if (stacks[y - 1].empty()) {      
                stacks[y - 1].push_back(-1);
                stacks[y - 1].push_back(y);
                // printf("y.push %ld \n", y);
            }

            // he won't try to access empty stack
            int sort = stacks[x - 1].back();
          
            stacks[x - 1].pop_back();
            stacks[y - 1].push_back(sort);
            // v_out.push_back(sort);
            printf("%ld\n", sort);
                 
 
        }
        // extra
        else if (query == 2) {
            // int x, k;
            // scanf("%ld, %ld", &x, &k);
            // v_out.push_back(stacks[x][y]);   
            printf("%ld\n", stacks[x - 1][y]);
        }
    }

    delete[] stacks;



}

int main() {
    int n, m;

    // std::vector<long int> v_out; 
    scanf("%d %d", &n, &m);

    // method 1:  array of vectors
    // case 12, 18, 19 memory limit exceeded
    method_1(n, m);

    // method 2: array of vectors, but directly printing out the results


    // print out results    
    // for(int i = 0; i < v_out.size(); i++) {
    //     printf("%ld\n", v_out[i]);
    // }
}   