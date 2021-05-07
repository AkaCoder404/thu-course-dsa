#include <iostream> 
#include <sstream> 
#include <vector>

bool isInteger(char c) {
    if ((int)c >= 48 && (int)c <= 58) {
        return true;
    }
    return false;
}


int main() {
    std::string str;
    std::string str1;
    std::vector<std::string> s; 
 
    bool read = true;
    while(read) {
        std::getline(std::cin, str);
        // if str is blank
        int blank = 0;
        while(str.length() == 0) {
            blank++;
            std::getline(std::cin, str);
            if (blank == 2) {
                break;
                read = false;
            }
            
            
        }
        // s.push_back(str);
        str1 += str;

        int start = 0;
        bool isInt = true;
        while(start < str.length()) {
            std::string temp = ""; 
            // if it is integer, check for all integers after it
            int c = 0;
            while(isInteger(str[start + c])) {
                temp += str[start + c];
                // std::cout << temp;
                c++;
            }          
            if(temp != "") {
                std::cout << temp << " ";
                s.push_back(temp);
            }
            start += c + 1;
        }

       
        std::cout << std::endl;
        // std::cout << str << std::endl;        
    }
    // std::cout << "lines read, sizeof "<< sizeof(str1) << "\n";
    // std::cout << str1 << "\n\n";
    //     for(int i = 0; i < s.size(); i++) 
    //         std::cout << s[i] << "\n";

    for(int i = 0; i < s.size(); i++) {
        std::cout << s[i] << "\n";
    }
    
}

// This line contains 1 integer "one".
// This line contains no integer.
// 233, next line is empty.

// If you got -123.456, you should output 123 and 456.
// Any digit string are considered integers, like 0123456 and 007.
// You may also need to consider cases like a0a12a345a6789a.