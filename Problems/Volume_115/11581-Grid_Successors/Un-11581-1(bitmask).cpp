#include <bits/stdc++.h>
using namespace std;

int d_i[4] = {1, -1, 0, 0};
int d_j[4] = {0, 0, 1, -1};

int Step(int g)
{
    int next = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            int sum = 0;
            for (int l = 0; l < 4; l++)
            {
                int ni = i + d_i[l], nj = j + d_j[l];
                if (ni < 0 || ni >= 3 || nj < 0 || nj >= 3) continue;
                sum += (g >> (ni * 3 + nj)) & 1;
            }
            if (sum % 2) next |= (1 << (i * 3 + j));
        }
    return next;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--)
    {
        int g = 0;
        for (int i = 0; i < 3; i++)
        {
            string str;
            cin >> str;
            for (int j = 0; j < 3; j++)
                if (str[j] == '1') g |= (1 << (i * 3 + j));
        }

        bool is_seen[512] = {};
        int cnt = 0;
        while (g && !is_seen[g])
        {
            is_seen[g] = true;
            g = Step(g);
            cnt++;
        }

        cout << (cnt == 0 ? -1 : cnt - 1) << '\n';
    }

    return 0;
}