#include <iostream> // cin, cout
#include <string>   // string, getline

using std::cin;
using std::cout;

int main()
{    
    std::string line;
    bool first = true;
    
    while (std::getline(cin, line))
    {   
    	// Print a newline before every case except the first one
        if (!first)
        {
        	cout << '\n';
        }	
        first = false;
        
        // count the ASCII frequency
        int cnt[129] = {0};
        for (char c : line)  
        {
            cnt[c]++;
        }
        
        // Output
        for (int freq = 1; freq <= 1000; freq++)
        {
            for (int ascii = 128; ascii > 31; ascii--)  
            {
                if (cnt[ascii] == freq)
                {
                    cout << ascii << ' ' << freq << '\n';
                }
            }
        }
    }
    
    return 0;
}