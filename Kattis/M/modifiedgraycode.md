---
Title: Modified Gray Code
Contest: North Central North America Regional Programming Contest
Contest_year:
  - "2023"
Contest_problem:
  - C
Kattis_Difficulty_Upper: 3.3
完成狀態: 1
---
#Bitwise 


題目的核心運算公式有差別：

|**類型**|**核心運算公式**|**運算本質**|
|---|---|---|
|**傳統格雷碼**|$G = K \oplus (K \gg 1)$|**相鄰位元間的 XOR**：目的是為了抵銷掉進位產生的多位元變動。|
|**偶數格雷碼**|$G = (K \ll 1) \mid \text{parity}(K)$|**末位補償**：目的是為了控制整體 $1$ 的總量（Hamming Weight）。|

# Code

```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int N;  cin >> N;
    while (N--)
    {
        unsigned K;  cin >> K;
        int result = K << 1;
        
        if (popcount(K) & 1)  { result |= 1; }
        
        cout << bitset<10>(result) << '\n';
    }
    
    return 0;
}
```