#include <bits/stdc++.h>
using namespace std;

int64_t f(int k, int i)
{
    if (i == 0)
        return 0;
    if (k == 0)
        return 1;
        
    if (i >= (1 << (k - 1)))  // i >= 2^(k-1)
        return f(k - 1, i - (1 << (k - 1))) + pow(3, k - 1) * 2;
    else
        return 2 * f(k - 1, i);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int T, kase = 1;
    cin >> T;
    while (T--)
    {
        int k, a, b;
        cin >> k >> a >> b;
        cout << "Case " << kase++ << ": ";
        
        int64_t ans = f(k, b) - f(k, a - 1);
        cout << ans << '\n';
    }
    
    return 0;
}