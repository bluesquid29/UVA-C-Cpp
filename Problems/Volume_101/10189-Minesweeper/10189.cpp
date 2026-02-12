#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; // line(row)
    int m; // column
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

        // 九宮格座標
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '*')  cout << '*';
                else
                {
                    int cnt = 0;
                    for (int k = 0; k < 8; k++)
                    {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if ((0 <= ni && ni < n) && (0 <= nj && nj < m) && grid[ni][nj] == '*')  cnt++;
                    }
                    cout << cnt;
                }
            }
            cout << '\n';
        }
    }
    
    return 0;
}
