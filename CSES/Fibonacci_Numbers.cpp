#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr i64 MOD = 1'000'000'007;

template <int N>
struct Matrix
{
    array<array<i64, N>, N> m = {};

    static Matrix Ident()
    {
        Matrix r;
        for (int i = 0; i < N; i++)  { r.m[i][i] = 1; }
        return r;
    }

    Matrix operator*(const Matrix& b) const
    {
        Matrix r;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    r.m[i][j] = (r.m[i][j] + m[i][k] * b.m[k][j]) % MOD;
        return r;
    }

    Matrix Pow(i64 p) const
    {
        if (p == 0)  { return Ident(); }
        auto a = *this;
        return (p & 1) ? a.Pow(p - 1) * a : (a * a).Pow(p / 2);
    }
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    i64 n;  cin >> n;

    Matrix<2> base;
    base.m = {{{0, 1}, {1, 1}}};

    auto res = base.Pow(n);
    cout << res.m[0][1] << '\n';

    return 0;
}