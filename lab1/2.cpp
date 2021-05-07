#include "stdio.h"
#include <iostream>
#include <vector>
#include <algorithm> 

int binarySearch(std::vector<long long int> &v, int l, int r, long long int x) {
    if (r>=l) { 
        int mid = l + (r - l)/2; 
        if (v[mid] == x) 
            return mid; 
        if (v[mid] > x) 
            return binarySearch(v, l, mid-1, x); 
        return binarySearch(v, mid+1, r, x); 
    } 
    return -1;
}


void method_1(std::vector<long long int> &v, std::vector<long long int> &v_out, long long int n, long long int m) {
    for(int i = 0; i < n; i++) {
        unsigned long long int x;
        scanf("%lld", &x);
        v.push_back(x);
        // algorithm's sort greatest to least
        // std::sort(v.begin(), v.end(), std::greater <int>());
        // algorithm's sort least to greatest
        std::sort(v.begin(), v.end());
        // use binarysearch to find the location
        v_out.push_back(v.size() - binarySearch(v, 0, v.size(), x));
        // for(int j = 0; j < v.size(); j++) {
        //     if(v[j] == x) {
        //         v_out.push_back(j + 1);
        //         break;
        //     }
        // }
    }
}

void method_2(std::vector<long int> &v, std::vector<long int> &v_out, long int n, long int m) {
    for(int i = 0; i < n; i++) {
        long int x;
        scanf("%ld", &x);
        // insert in correct position
        bool is_added = false;
        for(int j = 0; j < v.size(); j++) {
            if(x >= v[j]) {
                v.insert(v.begin() + j, x);
                v_out.push_back(j + 1);
                // printf("%d\n", j + 1);
                is_added = true;
                break;
            }
        }
        if (!is_added) {
            v.push_back(x);
            // printf("%d\n", v.size());
            v_out.push_back(v.size());
        }
        // for(int j = v.size() - 1; j >= 0; j--) {
        //     if(x <= v[j]) {
        //         v.insert(v.begin() + j + 1, x);
        //         v_out.push_back(j + 2);
        //         is_added = true;
        //         break;
        //     }
        // }
        // if (!is_added) {
        //     v.insert(v.begin(), x);
        //     v_out.push_back(1);
        // }
        



       
    }
}




int main() {
    long int n, m;
    scanf("%ld %ld", &n, &m);
    std::vector<long int> v;
    std::vector<long int> v_out;


    // method 1: sort using algorithm sort (which is in theory a quicksort)
    // last two time limit exceeded
    // method_1(v, v_out, n, m);

    // method 2: insert in correct position, insert position is the position of characte
    // last two time limit excceded
    // worst case when inputs keep gtting smaller and smaller, reverse to check if case 7, 8
    // still last two time limit exceeded
    method_2(v, v_out, n, m);
   

    // method 3: 




    // print out results
    for(int i = 0; i < v_out.size(); i++) {
        printf("%ld\n", v_out[i]);
    }
}