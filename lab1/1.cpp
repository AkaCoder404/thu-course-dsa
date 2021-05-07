#include "stdio.h"
#include <vector>       // std::vector
#include <algorithm>    // std::sort
#include <functional>   // std::greater

void swap(long long int *xp, long long int *yp)  {  
    long long int temp = *xp;  
    *xp = *yp;  
    *yp = temp;
} 

void temp(std::vector<long long int> &v) {

}

void bubble(std::vector<long long int> &v) {
    for(int i = 0; i < v.size() - 1; i++) {
        for (int j = 0; j < v.size() - i - 1; j++) {
            if (v[j] < v[j+1])  
                swap(&v[j], &v[j+1]); 
        }
    }
}

// quicksort
int partition(std::vector<long long int> &v, int left, int right) {
    long long int pivot = v[right];
	int i = left-1;
	for (int j = left; j < right; j++)
	{
		if(v[j] >= pivot)
		{
			i++;
			swap(&v[i], &v[j]);
		}
	}
	swap(&v[i+1], &v[right]);
	return i+1;
}

void quick_sort(std:: vector<long long int> &v, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(v, left, right);
        quick_sort(v, left, pivotIndex - 1);
        quick_sort(v, pivotIndex + 1, right);
    }
}

void method_1(std::vector<long long int> &v, std::vector<long long int> &v_out, long long int n, long long int m, long long int p, long long int x) {
    for(int i = 0; i < n; i++) {
        // std::cin >> p >> x;
        scanf("%lld %lld", &p, &x);
        if (p == 0) {
            v.push_back(x);
            bubble(v);
        }
        else if (p == 1) { 
            // std::cout << v[x-1];
            v_out.push_back(v[x-1]);  
        } 
    }
}

void method_2(std::vector<long long int> &v, std::vector<long long int> &v_out, long long int n, long long int m, long long int p, long long int x) {
    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &p, &x);
        if (p == 0) {
            v.push_back(x); 
        }
        else if(p == 1) {
            quick_sort(v, 0, v.size()-1);
            // std::sort(v.begin(), v.end(), std::greater<long long int>());
            v_out.push_back(v[x-1]);
        }
    }
}

void method_3(std::vector<long long int> &v, std::vector<long long int> &v_out, long long int n, long long int m, long long int p, long long int x) {
    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &p, &x);
        bool is_added = false; 
        if(p == 0) {
            for (int j = 0; j < v.size(); j++) {
                if ( x >= v[j]) {
                    v.insert(v.begin() + j, x);
                    is_added = true;
                    break;
                }
            } 
            if (!is_added) v.push_back(x);
        }
        if (p == 1) {
            v_out.push_back(v[x-1]);
        }
        
    }
}

int main() {
    long long int n, m;
    scanf("%lld %lld", &n, &m);
    // printf("%lld %lld",n, m);

    std::vector<long long int> v;
    std::vector<long long int> v_out;
    long long int p;
    long long int x;


    //method 1: sort everytime input is given with bubble sort
    //result: accepted time exceeded
    // method_1(v, v_out, n, m, p, x);

    // method 2: quicksort everytime output is needed 
    // result: accepted, time exceeded
    // method_2(v, v_out, n, m, p, x);


    // method 3: insert in the correct position 
    // result: accpeted, accepted
    method_3(v, v_out, n, m, p, x);

    // print out results
    for(int i = 0; i < v_out.size(); i++) {
        printf("%lld\n", v_out[i]);
    }
    
}