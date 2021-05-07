#include "stdio.h"
#include <vector>




void method_1(std::vector<std::pair<long int, long int> >&v) {
    
    long int *order = new long int[v.size()];
    std::vector<long int> del;

    std::vector<std::pair<long int, long int> > v_not;

    long int i = 0;
    long int round = 1;
    long int size = v.size();



    while(v.size() != 0) {
        // reaches end 
        if (i == v.size()) {
            i = 0;
            round++;
            v = v_not;
            v_not.clear();
        }

        // first element
        if (i == 0) {
            if (v.size() > 1 && v[i].first >= v[i + 1].first && v[i].first >= v[v.size()- 1].first) {
                order[v[i].second] = round;
                del.push_back(i);
                // v.erase(v.begin());
            }
            else if (v.size() != 1) {
                v_not.push_back(v[i]);
            }
            else if(v.size() ==1){
                order[v[i].second] = round;
                break;
            }
            
        } 
        // elements [1 ... n - 1]
        else if (i > 0 && i < v.size() - 1) {
            if (v[i].first >= v[i-1].first && v[i].first >= v[i+1].first) {
                order[v[i].second] = round;
                del.push_back(i);
            }
            else {
                v_not.push_back(v[i]);
            }
            
            // v.erase(v.begin()+i);
        }
        // nth element
        else if(i == v.size() - 1) {
            if (v[i] >= v[i - 1] && v[i] >= v[0]) {
                order[v[i].second] = round;
                del.push_back(i);
                // v.erase(v.end());
            }
            else {
                v_not.push_back(v[i]);
            }
        }
        
        // not deleted
        i++;
    }

    // print results
    for(long int j = 0; j < size; j++) printf("%ld\n", order[j]);
    delete[] order;
}

int main() {
    long int n; 
    scanf("%ld", &n);

    // (value, location)
    std::vector<std::pair<long int, long int>  >v; 
    
    long int m;
    for (long int i = 0; i < n; i++) {
        scanf("%ld", &m);
        v.push_back({m, i});
    }

    method_1(v);
}