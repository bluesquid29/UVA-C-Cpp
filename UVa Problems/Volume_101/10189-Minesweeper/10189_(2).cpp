#include <bits/stdc++.h>
using namespace std;

int n; // line(row)
int m; // column

int In_Range(int i, int j)
{
    return (0 <= i && i < n) && (0 <= j && j < m); // 1 or 0
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    bool is_first = true;
    int field = 1;
    
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)  break;
        if (!is_first)  cout << '\n';
        is_first = false;
        
        cout << "Field #" << field++ << ":\n";
        
        vector<vector<char>> grid(n, vector<char>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '*')  cout << '*';
                else
                {
			        // 九宮格座標 (額外函數)
					int cnt = 0;
			        if (In_Range(i-1, j-1) && grid[i-1][j-1] == '*')  cnt++;
			        if (In_Range(i-1, j  ) && grid[i-1][j  ] == '*')  cnt++;
			        if (In_Range(i-1, j+1) && grid[i-1][j+1] == '*')  cnt++;
			        if (In_Range(i  , j-1) && grid[i  ][j-1] == '*')  cnt++;
			        if (In_Range(i  , j+1) && grid[i  ][j+1] == '*')  cnt++;
			        if (In_Range(i+1, j-1) && grid[i+1][j-1] == '*')  cnt++;
			        if (In_Range(i+1, j  ) && grid[i+1][j  ] == '*')  cnt++;
			        if (In_Range(i+1, j+1) && grid[i+1][j+1] == '*')  cnt++;
                    cout << cnt;
                }
            }
            cout << '\n';
        }
    }
    
    return 0;
}

