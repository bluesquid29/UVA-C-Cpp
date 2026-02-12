## `<climits>` 在 UVa 的常見用途

### 1. **初始化極值**（最常見）

```cpp
// 找最小值
int min_val = INT_MAX;
for (int x : arr)
    min_val = min(min_val, x);

// 找最大值
int max_val = INT_MIN;
for (int x : arr)
    max_val = max(max_val, x);
```

### 2. **無窮大表示**

```cpp
// Dijkstra / Floyd-Warshall
int dist[100][100];
for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        dist[i][j] = (i == j) ? 0 : INT_MAX;

// DP 初始化
int dp[1000];
fill(dp, dp + 1000, INT_MAX);
dp[0] = 0;
```

### 3. **邊界檢查**

```cpp
// 避免溢位
if (a > INT_MAX / b)  // 改用除法判斷 a * b 是否溢位
    cout << "Overflow!\n";
```

### 4. **哨兵值**

```cpp
// 標記未訪問/不存在
int parent[1000];
fill(parent, parent + 1000, INT_MIN);  // -1 可能是有效值時用
```

## 常用常數

|常數|值|用途|
|---|---|---|
|`INT_MAX`|2147483647|最小值初始化、無窮大|
|`INT_MIN`|-2147483648|最大值初始化|
|`LLONG_MAX`|9×10^18|long long 極值|
|`LLONG_MIN`|-9×10^18|long long 極值|

## 注意事項

⚠️ **`INT_MAX + 1` 會溢位**

```cpp
// 錯誤
if (dist[u] + weight < dist[v])  // dist[u] 可能是 INT_MAX

// 正確
if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
```

⚠️ **`#include <bits/stdc++.h>` 已包含 `<climits>`**，不用額外 include

## 實戰範例

```cpp
// UVa 10003 - Cutting Sticks (DP)
int dp[51][51];
for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
        dp[i][j] = INT_MAX;

// UVa 821 - Page Hopping (Floyd)
int dist[100][100];
for (int i = 0; i < 100; i++)
    for (int j = 0; j < 100; j++)
        dist[i][j] = (i == j) ? 0 : INT_MAX;
```

**結論**：`INT_MAX` 主要用於**初始化極值**和**表示無窮大**，是 DP/圖論題的必備工具。

---
**不會衝突，可以一起用**

## 原因

### 1. **定義在不同命名空間**

```cpp
// <climits> 定義巨集
#define INT_MAX 2147483647

// <cstdint> 定義型別
typedef int int32_t;
typedef long long int64_t;
```

### 2. **用途互補**

|標頭|提供內容|典型用途|
|---|---|---|
|`<climits>`|`INT_MAX`, `LLONG_MAX`|極值初始化、無窮大|
|`<cstdint>`|`int32_t`, `int64_t`|固定寬度型別|

### 3. **實際使用**

```cpp
#include <bits/stdc++.h>  // 已包含兩者
using namespace std;

int main()
{
    // climits 的常數
    int min_val = INT_MAX;
    
    // cstdint 的型別
    int64_t big_num = 1e18;
    
    // 一起用
    int32_t ans = INT_MIN;
}
```

## UVa 場景

### 通常只需 `<climits>`

```cpp
// 大部分題目
int dp[1000];
fill(dp, dp + 1000, INT_MAX);
```

### 偶爾需要 `<cstdint>`

```cpp
// 明確需要 64 位元時
int64_t factorial(int n)  // 比 long long 更明確
{
    int64_t result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}
```

## 結論

- ✅ **完全不衝突**
- ✅ **`#include <bits/stdc++.h>` 已包含兩者**
- ✅ **通常只用 `INT_MAX` 就夠了**
- ✅ **需要固定寬度時才用 `int32_t`/`int64_t`**

**實務建議**：刷題時用 `int`/`long long` + `INT_MAX` 即可，除非題目明確要求固定寬度（罕見）。

# 3
## climits

:::info

- 提供各種資料型別的極值常數
- 用於：
    - 初始化極值（找最小用 `INT_MAX`、找最大用 `INT_MIN`）
    - 表示無窮大（圖論、DP）
    - 溢位檢查
- 常用：`INT_MAX`, `INT_MIN`, `LLONG_MAX`, `LLONG_MIN`
- 注意：`INT_MAX + 1` 會溢位，使用前需檢查 :::

**範例**

```cpp
// 初始化最小值
int min_val = INT_MAX;
for (int x : arr)
    min_val = min(min_val, x);

// Dijkstra 無窮大
int dist[100];
fill(dist, dist + 100, INT_MAX);

// 溢位檢查
if (dist[u] != INT_MAX && dist[u] + w < dist[v])
    dist[v] = dist[u] + w;
```

---

## 筆記建議結構

````markdown
## 標題

:::info
- 核心功能（一句話）
- 用於：（2-4 個重點場景）
- 常用：（列出最常用的）
- 注意：（陷阱/易錯點）
:::

**範例**
```cpp
// 2-3 個典型用法
````

```

**原則**：
- ✅ 先寫「是什麼」
- ✅ 再寫「什麼時候用」
- ✅ 最後補「要注意什麼」
- ✅ 範例要可直接執行/理解
```
