#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 Get_Pos(i64 x, i64 y)
{
    i64 s = x + y;
    return s * (s + 1) / 2 + x + 1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	i64 n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		i64 x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << "Case " << i << ": " << Get_Pos(x2, y2) - Get_Pos(x1, y1) << '\n';
	}
	
	return EXIT_SUCCESS;
}
