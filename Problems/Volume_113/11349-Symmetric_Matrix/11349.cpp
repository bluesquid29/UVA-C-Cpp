#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int T;	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		char c;
		int n;
		cin >> c >> c >> n;
		
		vector<vector<i64>> M(n, vector<i64>(n));
		// i64 M[100][100];
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> M[i][j];	
			}
		}
	
		bool is_symmetric = true;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (M[i][j] < 0 || M[i][j] != M[(n-1) - i][(n-1) - j])
				{
					is_symmetric = false;
					break;
				}
			}
		}
				
		if (is_symmetric)
		{
			cout << "Test #" << t << ": Symmetric.\n";
		}	
		else
		{
			cout << "Test #" << t << ": Non-symmetric.\n";
		}
	}
	
	return 0;
}
