---
CSES_group: Dynamic Programming
Title: Dice Combinations
CSES_ID: 1633
---
```cpp
#include <iostream>
#include <array>
using namespace std;

int constexpr MAX = 1'000'001;
int constexpr MOD = 1'000'000'007;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
    int n;  cin >> n;
        
    array<int, MAX> dp = {0};
    dp[0] = 1;
    for (int i = 1; i < MAX; ++i)
    {
    	for (int die = 6; die >= 1; --die)
    	{
    		if (i - die >= 0)  { dp[i] = (dp[i] + dp[i - die]) % MOD; }
    	}
    }
    
    cout << dp[n] << "\n";
    
    return 0;
}
```
