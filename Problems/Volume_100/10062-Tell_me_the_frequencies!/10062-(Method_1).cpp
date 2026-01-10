#include <iostream>  // cin, cout
#include <string>	 // string, getline
using namespace std;

int main()
{
    string line;
    bool first_case = true;
    
    while (getline(cin, line))
    {   
        if (!first_case) cout << '\n';
        first_case = false;
        
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
                    cout << ASCII << ' ' << i << '\n';
        		}
        	}
        }
    }
    
    return 0;
}