/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
    	cout << "Case #" << t << ":\n";
    	
    	string URL[10];
    	int V[10];
    	int r = 0; // highest relevance
    	
    	for (int j = 0; j < 10; j++)
    	{
    		cin >> URL[j] >> V[j];
    		r = max(r, V[j]);
    	}
    	
    	for (int j = 0; j < 10; j++)
    	{
    		if (V[j] == r)
    			cout << URL[j] << "\n";
    	}
    }

	return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ":\n";
        
        map<int, vector<string>> mp_relevance;
    	int r = 0; // highest relevance
        
        for (int i = 0; i < 10; i++)
        {
            string url;
            int V;
            cin >> url >> V;
            mp_relevance[V].push_back(url);
            r = max(r, V);
        }
        
        for (auto const& url : mp_relevance[r])
            cout << url << '\n';
    }
    
    return 0;
}