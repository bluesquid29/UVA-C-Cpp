#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	i64 S;
	i64 D;
	while (cin >> S >> D)
	{
		i64 sum = 0;
		while (sum < D)
		{
			sum += S;
			++S;
		}
		cout << --S << '\n';
	}
	
	return 0;
}
