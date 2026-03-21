#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	i64 n;  cin >> n;
	while (n--)
	{
		i64 s, d;  cin >> s >> d;
		
		if (s < d or (s - d) % 2 == 1)
		{
			cout << "impossible\n";
		}
		else
		{
			i64 a = (s + d) / 2;
			i64 b = (s - d) / 2;
			cout << a << ' ' << b << '\n';
		}
	}
	
	return 0;
}
