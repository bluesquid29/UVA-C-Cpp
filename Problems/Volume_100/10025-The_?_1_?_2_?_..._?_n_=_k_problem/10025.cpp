#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
	bool is_first = true;
    int n;
    cin >> n;
    
	while (n--)
	{
		if (!is_first) 
			cout << '\n';
		is_first = false;

    	int k;    	
		cin >> k;
		k = abs(k);
		
    	int sum = 0;
    	for (int i = 1; ; i++)
    	{
    		sum += i;
    		if (sum >= k && (sum - k) % 2 == 0)
    		{
    			cout << i << '\n';
    			break;
    		}		
    	}
	}
	return 0;
}


