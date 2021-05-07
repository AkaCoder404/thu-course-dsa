#include <iostream>
#include <string>
#include <vector>


int main(void)
{
    std::vector<int> v;
    std::string s;
    std::cin >> s;
    
    int t = s.length() + 1;
    while(t >= 0) 
    {
        t--;
        if ( t== 0) break;
        std::string sub_str = s.substr(0, t);
        // std::cout << "substr " << sub_str << "\n"; 
        int i, j;
        int val[sub_str.length()-1];
        for(i=1; i<sub_str.length(); i++)
        {
            for(j=0; j<i; j++)
            {
                if(sub_str[j]!=sub_str[sub_str.length()-i+j])
                {
                    val[i] = 0;
                    break;
                }
            }
            if(j==i)
                val[i-1] = 1;
        }
        int temp = -1;  
        for(i=0; i<sub_str.length()-1; i++)
        {
            if(val[i]==1)
            {
                if(i>temp)
                    temp = i;
            }
        }
        if(temp==-1)
            // std::cout<<"0"<<std::endl;
            v.push_back(0);
        else
        {
            // std::cout << "longest substr : ";
            // for(i=0; i<=temp; i++)
            //     std::cout << sub_str[i];
            // std::cout << " ";
            // std::cout << temp + 1;
            v.push_back(temp+1);
            // std::cout << std::endl;
        }    
    }

    for (int i = v.size()-1; i >= 0; i--) std::cout << v[i] << "\n";
    return 0;
}
