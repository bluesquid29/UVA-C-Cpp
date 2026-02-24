#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int t;	cin >> t;
	while (t--)
	{
		int n;	cin >> n;
		
		vector<int> x(n);
		for (auto& i : x)	cin >> i;
		
		sort(x.begin(), x.end());
		
		int min_d = (x.back() - x.front()) * 2;
		cout << min_d << '\n';
	}	
	
	return 0;
}
