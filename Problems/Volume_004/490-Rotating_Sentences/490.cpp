#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    vector<string> rows;
    int max_len = 0;

    string s;
    while (getline(cin, s))
    {
        max_len = max(max_len, (int)s.size());
        rows.push_back(s);
    }
    reverse(rows.begin(), rows.end());

    for (int i = 0; i < (int)max_len; ++i)
    {
        // for (int j = (int)rows.size() - 1; j >= 0; --j)
        for (int j = 0; j < (int)rows.size(); ++j)
        {
            if (i < (int)rows[j].size())  { cout << rows[j][i]; }
            else                           { cout << ' '; }
        }
        cout << '\n';
    }

    return 0;
}