#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int N;  cin >> N;
	while (N--)
	{
		i64 n, k;  cin >> n >> k;
		
		cout << (k ^ (k >> 1)) << '\n';
	}
	
	return 0;
}
