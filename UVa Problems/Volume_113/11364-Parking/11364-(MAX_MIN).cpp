#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int t;	cin >> t;
	while (t--)
	{
		int n;	cin >> n;
		
		int max_pos = INT_MIN;
		int min_pos = INT_MAX;
		
		vector<int> x(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> x[i];
			if (x[i] > max_pos)
			{
				max_pos = x[i]; 
			}
			if (x[i] < min_pos)
			{
				min_pos = x[i];
			}
		}
		
		int min_d = (max_pos - min_pos) * 2;
		cout << min_d << '\n';
	}	
	
	return 0;
}
