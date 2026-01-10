#include <iostream>
#include <string>
#include <algorithm>
#include <print>

int main()
{
    std::string s; 
    
    while (std::getline(std::cin, s))
    {
        int len = s.length();
        int word_start = 0;
        
        for (int i = 0; i <= len; i++)
        {
            if (i == len || s[i] == ' ')
            {
                std::reverse(s.begin() + word_start, s.begin() + i);
                word_start = i + 1;
            }
        }
        
        std::cout << s << '\n';
    }
    
    return 0;
}