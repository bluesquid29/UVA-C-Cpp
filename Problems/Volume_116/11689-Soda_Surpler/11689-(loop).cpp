#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int N;  cin >> N;
	while (N--)
	{
		int e;
		int f;
		int c;
		cin >> e >> f >> c;
		
		int t = e + f;  // 所有空瓶
		int cnt = 0;    // 總共喝幾瓶汽水
		while (t >= c)
		{
	    	cnt += t / c;
	    	t = t / c + t % c; 
		}
	    cout << cnt << '\n';
	}
	
	return 0;
}
