#include <bits/stdc++.h>
using namespace std;

int main() 
{	
	ios_base::sync_with_stdio(false); cin.tie(nullptr); 
    int N;
    while (cin >> N) 
    {	
        vector<int> prices(N);
        for (int i = 0; i < N; i++)
        {
            cin >> prices[i];
        }
        
        int M;  // budget
        cin >> M;
        
        sort(prices.begin(), prices.end());
        
        int book1, book2;
        int min_diff = INT_MAX; 
        for (int i = 0; i < N; i++) 
        {
            for (int j = i + 1; j < N; j++) 
            {
                if (prices[i] + prices[j] == M) 
                {
                    int diff = abs(prices[i] - prices[j]);
                    if (diff < min_diff) 
                    {
                        min_diff = diff;
                        book1 = prices[i];
                        book2 = prices[j];
                    }
                }
            }
        }
        
        cout << "Peter should buy books whose prices are " << book1 << " and " << book2 << ".\n\n";
    }
    
    return 0;
}