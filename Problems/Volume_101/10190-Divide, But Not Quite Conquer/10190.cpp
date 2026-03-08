#include <iostream>
#include <vector>
using namespace std;
using i64 = long long;

int main()
{
    i64 n, m;   
    while (cin >> n >> m)
    {
        if (n == 0 || m == 0)  { cout << "Boring!\n"; continue; }
        if (n == 1 || m == 1)  { cout << "Boring!\n"; continue; }
        
        vector<i64> v;
        v.push_back(n);
        while (n > 1 && n % m == 0)
        {
            n /= m;
            v.push_back(n);
        }
        
        if (n == 1)
        {
            for (int i = 0; i < (int)v.size() - 1; ++i)  { cout << v[i] << ' '; }
            cout << 1 << '\n';     
        }
        else
        {
            cout << "Boring!" << '\n'; 
        } 
    }
    
    return 0;
}
