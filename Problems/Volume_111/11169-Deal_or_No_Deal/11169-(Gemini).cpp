#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;

// 15 個盒子的固定金額
const long long amounts[15] = {
    10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 
    10000, 20000, 50000, 100000, 200000, 500000
};

// 儲存 DP 狀態的結構
struct Result {
    double prob;
    double exp_val;
};

long long limit_amt;
long long p1, p2, p3, p4;
Result dp[1 << 15];
bool visited[1 << 15];

// 取得該狀態中為 1 的位元數 (剩餘盒子數)
int count_bits(int mask) {
    int cnt = 0;
    for (int i = 0; i < 15; ++i) {
        if (mask & (1 << i)) cnt++;
    }
    return cnt;
}

// 遞迴計算組合轉移
// mask: 當前狀態
// bit_idx: 目前考慮要不要關閉的位元索引
// to_remove: 還需要關閉幾個盒子
// next_states: 收集所有可能的下一輪狀態
void get_next_states(int mask, int bit_idx, int to_remove, vector<int>& next_states) {
    if (to_remove == 0) {
        next_states.push_back(mask);
        return;
    }
    if (bit_idx >= 15) return;
    
    // 情況 1：這個盒子還沒開，我們選擇在這裡打開它 (將 bit 設為 0)
    if (mask & (1 << bit_idx)) {
        get_next_states(mask ^ (1 << bit_idx), bit_idx + 1, to_remove - 1, next_states);
    }
    // 情況 2：不打開這個盒子，繼續往下找
    get_next_states(mask, bit_idx + 1, to_remove, next_states);
}

// 核心 DFS 記憶化搜尋
Result solve(int mask) {
    if (visited[mask]) return dp[mask];
    
    int n = count_bits(mask);
    long long S = 0;
    for (int i = 0; i < 15; ++i) {
        if (mask & (1 << i)) {
            S += amounts[i];
        }
    }
    
    // 判斷是否為需要報價的決策點
    if (n == 11 || n == 8 || n == 5 || n == 2) {
        long long p = 0;
        if (n == 11) p = p1;
        else if (n == 8) p = p2;
        else if (n == 5) p = p3;
        else if (n == 2) p = p4;
        
        // 根據公式計算報價: (S * p) / (100 * n) 取整數
        long long offer = (S * p) / (100LL * n);
        
        // 策略：報價 >= 目標限制，接受交易並結束遊戲
        if (offer >= limit_amt) {
            visited[mask] = true;
            return dp[mask] = {1.0, (double)offer};
        }
        
        // 如果是最後一輪 (n==2) 且拒絕了報價，只能開自己的盒子
        if (n == 2) {
            double prob_sum = 0;
            for (int i = 0; i < 15; ++i) {
                if (mask & (1 << i)) {
                    if (amounts[i] >= limit_amt) {
                        prob_sum += 1.0;
                    }
                }
            }
            visited[mask] = true;
            return dp[mask] = {prob_sum / 2.0, (double)S / 2.0};
        }
    }
    
    // 如果沒有接受報價，或處於初始狀態 (n=15)，則需要打開盒子進入下一輪
    int to_open = (n == 15) ? 4 : 3;
    vector<int> next_states;
    get_next_states(mask, 0, to_open, next_states);
    
    double total_prob = 0;
    double total_exp = 0;
    
    // 將所有可能的分支結果加總
    for (int next_mask : next_states) {
        Result res = solve(next_mask);
        total_prob += res.prob;
        total_exp += res.exp_val;
    }
    
    // 取平均值
    int ways = next_states.size();
    visited[mask] = true;
    return dp[mask] = {total_prob / ways, total_exp / ways};
}

int main() {
    // 優化 I/O 速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while (cin >> limit_amt && limit_amt != 0) {
        cin >> p1 >> p2 >> p3 >> p4;
        
        // 初始化記憶化陣列
        memset(visited, false, sizeof(visited));
        
        // 初始狀態為 15 個盒子全關 (二進位 111111111111111 即 (1 << 15) - 1)
        int initial_mask = (1 << 15) - 1;
        Result ans = solve(initial_mask);
        
        // 輸出格式：機率保留 6 位小數，期望值保留 2 位小數
        cout << fixed << setprecision(6) << ans.prob << " " 
             << setprecision(2) << ans.exp_val << "\n";
    }
    
    return 0;
}