#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

string solve(i64 Q)
{
	string s;  // output
	
	for (int i = 9; i >= 2; --i)
	{
		while (Q % i == 0)
		{
			Q /= i;
			s += to_string(i);
		}
	}
	
	if (Q != 1)  { return "-1"; }
	else
	{
		reverse(s.begin(), s.end());
		return s;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int N;  cin >> N;
	while (N--)
	{
		i64 Q;  cin >> Q;
		
		if      (Q == 0)  { cout << 0 << '\n'; }
		else if (Q == 1)  { cout << 1 << '\n'; }
		else              { cout << solve(Q) << '\n'; }
	}
	
	return 0;
}
