#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int N;
	while (cin >> N)
	{
		if (N == 0)  break;
		
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 1; i <= N; i++)
		{
			int n;
			cin >> n;
			pq.push(n);
		}
		
		int sum = 0;
		while (pq.size() > 1)
		{
			int u = pq.top();
			pq.pop();
			
			int v = pq.top();
			pq.pop();
			
			pq.push(u + v);
			sum += u + v;
		}
		
		cout << sum << '\n';
	}	
	
	return 0;
}
