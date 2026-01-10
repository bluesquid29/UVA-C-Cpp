#include <iostream>  // cin, cout
#include <string>	 // string, getline

int main()
{
    std::string line;
    bool first = true;
    
    while (std::getline(std::cin, line))
    {   
        if (!first) std::cout << '\n';
        first = false;
        
        // count the ASCII frequency
        int cnt[129] = {0};
        for (int i = 0; line[i] != '\0'; i++)
        {
            cnt[(int)(line[i])]++;
        }
        
        // Output
        for (int i = 1; i <= 1000; i++)
        {
            for (int ASCII = 126; ASCII >= 32; ASCII--)
        	{
                if (cnt[ASCII] == i)
        		{
                    std::cout << ASCII << ' ' << i << '\n';
        		}
        	}
        }
    }
    
    return 0;
}
