#include <bits/stdc++.h>
using namespace std;

int side[6][6];
vector<int> path;

void DFS(int u, int cnt) 
{
    if (cnt == 8) 
    {
        for (int node : path)  cout << node;
        cout << '\n';
        return;
    }
    
    for (int v = 1; v <= 5; v++) 
    {
        if (side[u][v] > 0) 
        { 
            side[u][v]--; 
            side[v][u]--; 
            path.push_back(v);

            DFS(v, cnt + 1);

            path.pop_back();
            side[u][v]++; 
            side[v][u]++; 
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    
    // 建立所有的邊
    side[1][2] = side[2][1] = 1;
    side[1][3] = side[3][1] = 1;
    side[1][5] = side[5][1] = 1;
    side[2][3] = side[3][2] = 1;
    side[2][5] = side[5][2] = 1;
    side[3][4] = side[4][3] = 1;
    side[3][5] = side[5][3] = 1;
    side[4][5] = side[5][4] = 1;
    
    path.push_back(1);  // 起點是 1
    DFS(1, 0);

    return 0;
}
