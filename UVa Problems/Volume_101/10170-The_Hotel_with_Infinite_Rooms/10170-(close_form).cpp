#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    i64 S;
    i64 D;
    while (cin >> S >> D) 
    {
        double b = 2.0 * S - 1.0;
        i64 k = ceil((-b + sqrt(b * b + 8.0 * D)) / 2.0);
        
        cout << S + k - 1 << '\n';
    }
    
    return 0;
}
