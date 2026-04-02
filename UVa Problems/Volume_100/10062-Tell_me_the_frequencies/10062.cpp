#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	bool is_first_testcase = true;
	char s[19];
	while (cin.getline(s, 20,'\n'))
	{
    	if (!is_first_testcase)  { cout << '\n'; }  is_first_testcase = false;
    	
    	// 數每個ASCII出現幾次
		vector<int> ASCII(129, 0);
		for (char c : s)  { ASCII[c]++; }
		
		// 一行最多1000個字，那頻率最高為1000。先輸出頻率最低
		for (int freq = 1; freq <= 1000; freq++)
		{
			// 若頻率相同，由大到小輸出其ASCII 
			for (int c = 128; c >= 0; c--)
			{
				if (ASCII[c] == freq)
				{
					cout << c << ' ' << freq << '\n';
				}
			}
		}
	}
	
	return 0;
}
