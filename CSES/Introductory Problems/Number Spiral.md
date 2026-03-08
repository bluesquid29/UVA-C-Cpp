# 題解

比如說：

|       |       |       |        |     |
| ----- | ----- | ----- | ------ | --- |
| **1** | 2     | 9     | 10     |     |
| 4     | **3** | 8     | 11     |     |
| 5     | 6     | **7** | 12     |     |
| 16    | 15    | 14    | **13** |     |
|       |       |       |        | a_n |

推導下列公式：

$$
\large
\begin{align}
a_{1} &= 1 \\
a_{2} &= 3 = 1 + 2 \\
a_{3} &= 7 = 1 + 2 + 4 \\
a_{4} &= 13 = 1 + 2 + 4 + 6 \\
\vdots \\
a_{n} &= 1 + 2 \sum_{k=1}^{n-1} k = 1 + (n - 1)\cdot n
\end{align}
$$

接下來按照題意分開討論：

- x > y
	- x is odd
	- s is even
- y > x
	- y is odd
	- y is even

---

# Code

```cpp
#include <iostream>
using namespace std;
using i64 = long long;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int t;  cin >> t;
	while (t--)
	{
		i64 x;
		i64 y;
		cin >> x >> y;
		
		i64 ans = 0;
		if (x > y)
		{
			ans = 1 + (x-1) * x;
			if (x % 2 == 1)
			{
				ans -= (x - y);
			}
			else
			{
				ans += (x - y);
			}
		}
		else
		{
			ans = 1 + (y-1) * y;
			if (y % 2 == 1)
			{
				ans += (y - x);
			}
			else
			{
				ans -= (y - x);
			}
		}
		cout << ans << '\n' ;
	}
	
	return 0;
}
```
