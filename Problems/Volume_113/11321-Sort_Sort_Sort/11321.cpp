#include <bits/stdc++.h>
using namespace std;

int N, M;

bool cmp(int x, int y)
{
    if ((x % M) != (y % M))
    {
        return (x % M) < (y % M);
    } 
    else // ((x % M) == (y % M))
    {
        if ((x % 2 != 0) && (y % 2 != 0))
        {
            return x > y;
        }
        else if ((x % 2 == 0) && (y % 2 == 0))
        {
            return x < y;
        } 
        else 
        {
            return (x % 2 != 0);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    while (cin >> N >> M)
    {
        cout << N << " " << M << '\n';
        if (N == 0 && M == 0) break;
        
        vector<int> a(N);
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
        }
        
        sort(a.begin(), a.end(), cmp);
        
        for (int i = 0; i < N; i++)
        {
            cout << a[i] << '\n';
        }
    }
    
    return 0;
}