#include <bits/stdc++.h>
using namespace std;

const int INF = 9999;

string S, T;
int n;
bool is_from_S[18][19];
vector<int> mp_self_match[18][19];
int memo[1 << 18];

// Check if T[i..i+len-1] matches src[p..p+len-1] forward or reversed
auto Match = [](const string& src, int p, const string& dst, int i, int len)
{
    bool fwd = true, rev = true;
    for (int k = 0; k < len; k++)
    {
        if (src[p + k] != dst[i + k])         fwd = false;
        if (src[p + k] != dst[i + len - 1 - k]) rev = false;
    }
    return fwd || rev;
};

int Solve(int mask)
{
    if (mask == (1 << n) - 1) return 0;
    if (memo[mask] != -1) return memo[mask];

    int ans = INF;
    for (int i = 0; i < n; i++)
    {
        if (mask & (1 << i)) continue;

        int gap = 0;
        while (i + gap < n && !(mask & (1 << (i + gap)))) gap++;

        for (int len = gap; len >= 1; len--)
        {
            bool can = is_from_S[i][len];
            if (!can)
                for (int p : mp_self_match[i][len])
                {
                    int src_mask = ((1 << len) - 1) << p;
                    if ((mask & src_mask) == src_mask) { can = true; break; }
                }

            if (can)
            {
                int sub = Solve(mask | (((1 << len) - 1) << i));
                if (sub < INF) ans = min(ans, 1 + sub);
                break;
            }
        }
    }
    return memo[mask] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> S >> T;
        n = T.size();

        bool is_possible = true;
        for (char c : T)
            if (S.find(c) == string::npos) { is_possible = false; break; }
        if (!is_possible) { cout << "impossible\n"; continue; }

        int m = S.size();
        for (int i = 0; i < n; i++)
            for (int len = 1; i + len <= n; len++)
            {
                is_from_S[i][len] = false;
                for (int k = 0; k <= m - len && !is_from_S[i][len]; k++)
                    if (Match(S, k, T, i, len)) is_from_S[i][len] = true;

                mp_self_match[i][len].clear();
                for (int p = 0; p + len <= n; p++)
                    if (p != i && Match(T, p, T, i, len))
                        mp_self_match[i][len].push_back(p);
            }

        memset(memo, -1, sizeof(int) * (1 << n));
        int ans = Solve(0);
        cout << (ans < INF ? to_string(ans) : "impossible") << '\n';
    }
    return 0;
}