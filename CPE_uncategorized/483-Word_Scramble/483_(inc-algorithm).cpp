#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string text_line;
    
    while (std::getline(std::cin, text_line))
    {
        int len = text_line.length();
        int word_start = 0;
        
        for (int i = 0; i <= len; i++)
        {
            if (i == len || text_line[i] == ' ')
            {
                std::reverse(text_line.begin() + word_start, text_line.begin() + i);
                word_start = i + 1;
            }
        }
        
        std::cout << text_line << '\n';
    }
    
    return 0;
}