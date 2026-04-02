#include <bits/stdc++.h>
using namespace std;

int d_i[4] = {1, -1, 0, 0};
int d_j[4] = {0, 0, 1, -1};

int a[5][5], b[5][5];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--)
    {
        for (int i = 0; i < 3; i++)
        {
            string str;
            cin >> str;
            for (int j = 0; j < 3; j++)
                a[i][j] = str[j] - '0';
        }

        int ans = -2; // sentinel: sequence never hit zero
        for (int k = 1; k <= 6; k++)
        {
            bool is_zero = true;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                {
                    b[i][j] = a[i][j];
                    if (a[i][j]) is_zero = false;
                }

            if (is_zero) // f^(k-1)(g) == 0, so mu = k-1
            {
                ans = k - 2; // mu - 1
                break;
            }

            // compute f(a) -> a
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                {
                    int cur = 0;
                    for (int l = 0; l < 4; l++)
                    {
                        int x = i + d_i[l], y = j + d_j[l];
                        if (x < 0 || x > 2 || y < 0 || y > 2) continue;
                        cur += b[x][y];
                    }
                    a[i][j] = cur % 2;
                }
        }

        cout << ans << '\n';
    }

    return 0;
}