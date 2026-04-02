---
UVA_ID: 451
Title: Untitled
Contest:
Contest_year:
Contest_problem:
Kattis_Difficulty_Up:
完成狀態: 0
---
# 題解

> [!warning]

# Code

```cpp

```

---

# I/O

## Editor's Selection

### I

```

```

### O

```

```

---

# 精選英文



---

# Reference

```
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	multiset<int> trees;
	
	int Q;  cin >> Q;
	while (Q--)
	{
		int q;  cin >> q;
		int h;  cin >> h;
		
		if (q == 1)  { trees.insert(h); }
		if (q == 2)  { trees.erase(trees.begin(), trees.upper_bound(h)); }
		
		cout << trees.size() << '\n'; 
	}
	
	return 0;
}
```

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int N;  cin >> N;
	int M;  cin >> M;
	
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i)  { cin >> A[i] >> B[i]; }
	
	map<int, int> diff;
	for (int i = 1; i <= M; ++i)  { diff[i] = 0; }
	for (int i : A)               { diff[i]--; }
	for (int i : B)               { diff[i]++; }
	
	for (auto& [key, value] : diff)  { cout << value << '\n'; }
	
	return 0;
}

```