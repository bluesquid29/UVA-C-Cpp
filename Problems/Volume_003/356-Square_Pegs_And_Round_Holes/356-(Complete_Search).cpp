#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    bool is_first = true;

    while (cin >> n)
    {
        if (!is_first) cout << '\n';
        is_first = false;

        double r = n - 0.5;
        int cnt_inside = 0, cnt_cross = 0;

        // y[i] = circle height at x = i (clamped to 0 if outside)
        vector<double> y(n + 1);
        for (int i = 0; i <= n; i++)
            y[i] = (i < r) ? sqrt(r*r - (double)i*i) : 0.0;

        for (int i = 0; i < n; i++)
        {
            int lo = (int)floor(y[i + 1]);
            int hi = (int)ceil(y[i]);
            cnt_inside += lo;
            cnt_cross  += hi - lo;
        }

        cout << "In the case n = " << n << ", " << 4 * cnt_cross  << " cells contain segments of the circle.\n";
        cout << "There are "       << 4 * cnt_inside << " cells completely contained in the circle.\n";
    }

    return 0;
}