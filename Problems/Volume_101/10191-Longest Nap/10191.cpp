#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int Parse_Time(const string& s)
{
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, day = 0;
    while (cin >> n)
    {
        day++;
        cin.ignore();

        vector<pair<int, int>> events;
        for (int i = 0; i < n; i++)
        {
            string line;
            getline(cin, line);
            int s = Parse_Time(line.substr(0, 5));
            int e = Parse_Time(line.substr(6, 5));
            events.push_back({s, e});
        }
        sort(events.begin(), events.end());

        const int DAY_START = 10 * 60;
        const int DAY_END   = 18 * 60;

        int best_start = DAY_START, best_dur = 0, cur = DAY_START;

        for (auto& [s, e] : events)
        {
            int dur = s - cur;
            if (dur > best_dur)  { best_dur = dur; best_start = cur; }
            cur = max(cur, e);
        }

        // 最後一個事件到 18:00 的空隙
        int dur = DAY_END - cur;
        if (dur > best_dur)  { best_dur = dur; best_start = cur; }

        // 輸出
        int sh = best_start / 60, sm = best_start % 60;
        int dh = best_dur   / 60, dm = best_dur   % 60;

        cout << "Day #" << day << ": the longest nap starts at "
             << setfill('0') << setw(2) << sh << ":" << setw(2) << sm
             << " and will last for ";

        if (dh > 0)  { cout << dh << " hours and " << dm << " minutes.\n"; }
        else         { cout << dm << " minutes.\n"; }
    }

    return 0;
}