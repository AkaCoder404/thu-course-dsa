#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <ctime>
#include <ratio>
#include <chrono>

// std::string * nums = new std::string[1000001];

std::vector<std::string> nums;

std::string add(std::string numOne, std::string numTwo) {
 
    std::vector<int>finalsum; 
  
    // stop adding all numbers when add more than 10? digits because it doesn't matter anymore 
    
    int carry=0;     
    int process=0;

    int limit= numOne.length() > 16 ? 10 : 17;
    // int limit=17;

    long int i = numOne.size()-1,j=numTwo.size()-1; 
    while((i>=0) && (j>=0) && process < limit){     
        int x = (numOne[i]-'0') + (numTwo[j]-'0') + carry; 
        finalsum.push_back(x%10);  
        carry = x/10;              
        process++;
        i--;                       
        j--;
    }
    
    while(i>=0 && process < limit){          // If the number 1 was greater than number 2, then there must be some digits to be taken care off.
        int x = (numOne[i]-'0') + carry;  // Add the remaining digits to the carry one by one and store the unit digit.
        finalsum.push_back(x%10);
        carry = x/10;            // update the carry from each step.
        i--;
    }
    
    
    while(j>=0 && process < limit){       // If the number 2 was greater than number 1, then there must be some digits to be taken care off.
        int x = (numTwo[j]-'0') + carry; // Add the remaining digits to the carry one by one and store the unit digit.
        finalsum.push_back(x%10);
        carry = x/10;         // update the carry from each step.
        j--;
    }
       
    while(carry && process < limit){   //If after finishing addition of the two numbers, if there is still carry/leftover then we need to take it into the final sum.
        finalsum.push_back(carry%10); // Store digit one by one.
        carry=carry/10;       // Reduce carry
    }
    /* Step 5 starts here */
    std::string strSum;
    for(int k = finalsum.size()-1;k>=0 ;k--){  // Since vector pushes value at last, the most significant digits starts at the end of the vector. Thus print reverse.
        strSum += std::to_string(finalsum[k]);
    } 
    //std::cout << strSum << "\n";
    if (limit == 10) return "......"+strSum;
    else return strSum;
}


void three(int n, int start) {
    for (int i = 3; i <= 3 + n - start; i++) {
        nums.insert(nums.end(), add(add(nums[i-1], nums[i-1]), add(nums[i-2], nums[i-2])));
    }
}

int main() {

    long int n; 
    std::cin >> n;
 
    
    
    using namespace std::chrono;
 
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
        
    
    int start = 3;
    
    if(n >= 900000) {
        nums.insert(nums.end(), "......7272664064");
        nums.insert(nums.end(), "......4433328128");
        nums.insert(nums.end(), "......3411984384");
        start = 900000 + 3;
    }

    else if(n >= 500000) {
        nums.insert(nums.end(), "......0449057792");
        nums.insert(nums.end(), "......0156895232");
        nums.insert(nums.end(), "......1211906048");
        start = 500000 + 3;

    }
    else if(n >= 200000) {
        nums.insert(nums.end(), "......0321057792");
        nums.insert(nums.end(), "......6236895232");
        nums.insert(nums.end(), "......3115906048");
        start = 200000 + 3;
    }
    else if (n >= 100000) {
        nums.insert(nums.end(), "......2086278144");
        nums.insert(nums.end(), "......2033776640");
        nums.insert(nums.end(), "......8240109568");
        start = 100000 + 3;
    }
    else {
        nums.insert(nums.end(), "0");
        nums.insert(nums.end(), "3");
        nums.insert(nums.end(), "9");
    }
    
    three(n, start);

    if(nums[n - start + 3].length() > 16) {
        std::cout << "......";
        for(int i = nums[n-start + 3].length()-10; i < nums[n-start + 3].length(); i++) {
            std::cout << nums[n-start + 3][i];
        }
    }
    else std::cout << nums[n - start + 3];
    
    std::cout << "\n";   
  
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
  
    duration<double, std::milli> time_span = t2 - t1;
 
    // std::cout << "It took me " << time_span.count() << " milliseconds.\n";


    
}
