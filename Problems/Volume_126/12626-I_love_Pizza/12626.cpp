#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    
    int need[26] = {0};
    need['M' - 'A'] = 1;
    need['A' - 'A'] = 3;
    need['R' - 'A'] = 2;
    need['G' - 'A'] = 1;
    need['I' - 'A'] = 1;
    need['T' - 'A'] = 1;
    
    int N;
    cin >> N;
    while (N--)
    {
        string s;
        cin >> s;
        
        int cnt[26] = {0};
        for (char ch : s)
            cnt[ch - 'A']++;
        
        int ans = INT_MAX;
        for (int i = 0; i < 26; i++)
            if (need[i] > 0)
                ans = min(ans, cnt[i] / need[i]);	
        	
        cout << ans << '\n';
    }
    
    return 0;
}