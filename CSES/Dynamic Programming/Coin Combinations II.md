---
CSES_group: Dynamic Programming
Title: Coin Combinations II
CSES_ID: 1636
---
$$
dp[i] = \sum_{j=1}^{6} dp[i-j] \quad (i-j \geq 0)
$$

---

```cpp
#include <iostream>
#include <array>
#include <vector>
using namespace std;

int constexpr MAX = 1'000'001;
int constexpr MOD = 1'000'000'007;

int main()
{
    int n;  cin >> n;
    int x;  cin >> x;
        
    vector<int> coins(n);   
    for (int i = 0; i < n; i++)  { cin >> coins[i]; }
    
    array<int, MAX> dp = {0};
    dp[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = coins[i]; j < MAX; ++j)
        {
            dp[j] = (dp[j] + dp[j - coins[i]]) % MOD;    
        }    
    }
    
    cout << dp[x] << "\n";
    
    return 0;
}
```
