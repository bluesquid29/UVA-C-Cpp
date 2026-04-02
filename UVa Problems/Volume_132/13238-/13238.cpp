#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

// 使用全域扁平化陣列優化快取存取
int dp[55][4500]; // 假設 N 達 110, S 達 4000 左右 (N^2/3)
int ndp[55][4500];

void solve() {
    vector<int> queries;
    int n;
    int max_n = 0;
    while (cin >> n) {
        queries.push_back(n);
        if (n > max_n) max_n = n;
    }
    if (queries.empty()) return;

    // 預先計算每個 N 對應的目標位移 S
    vector<int> targets(max_n + 1);
    int max_s_needed = 0;
    for (int i = 1; i <= max_n; ++i) {
        targets[i] = (i * i) / 3;
        if (targets[i] > max_s_needed) max_s_needed = targets[i];
    }

    // 答案存儲
    vector<int> final_answers(max_n + 1, 0);

    // 初始化：0 個元素，0 個 open cycles，總位移 0
    dp[0][0] = 1;

    for (int i = 0; i < max_n; ++i) {
        // 限制當前 j 的範圍 (j 不會超過 i+1 且最終要歸零)
        int limit_j = min(i + 1, max_n - i);
        int current_s_limit = (i * i); // 粗略估計當前可能最大位移

        // 清空 ndp
        for (int j = 0; j <= limit_j; ++j) {
            for (int s = 0; s <= max_s_needed; ++s) ndp[j][s] = 0;
        }

        for (int j = 0; j <= i && j < 52; ++j) {
            for (int s = 0; s <= max_s_needed; ++s) {
                if (dp[j][s] == 0) continue;

                long long ways = dp[j][s];

                // 1. 延續 (2j + 1 種方法)
                int ns1 = s + 2 * j;
                if (ns1 <= max_s_needed) {
                    ndp[j][ns1] = (ndp[j][ns1] + ways * (2 * j + 1)) % MOD;
                }

                // 2. 開啟 (1 種方法)
                if (j + 1 < 52) {
                    int ns2 = s + 2 * (j + 1);
                    if (ns2 <= max_s_needed) {
                        ndp[j + 1][ns2] = (ndp[j + 1][ns2] + ways) % MOD;
                    }
                }

                // 3. 閉合 (j*j 種方法)
                if (j > 0) {
                    int ns3 = s + 2 * (j - 1);
                    if (ns3 <= max_s_needed) {
                        ndp[j - 1][ns3] = (ndp[j - 1][ns3] + (ways * j % MOD * j)) % MOD;
                    }
                }
            }
        }

        // 轉移並記錄 N = i + 1 的結果
        for (int j = 0; j <= limit_j; ++j) {
            for (int s = 0; s <= max_s_needed; ++s) dp[j][s] = ndp[j][s];
        }

        int current_n = i + 1;
        int t = targets[current_n];
        if (t % 2 == 0 && t <= max_s_needed) {
            final_answers[current_n] = dp[0][t];
        }
    }

    // 輸出
    for (int q : queries) {
        if (q == 0) cout << 0 << "\n";
        else cout << final_answers[q] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}