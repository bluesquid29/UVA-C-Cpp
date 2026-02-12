#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    int n = 1;
    while (cin >> N)
    {
        vector<int> b(N);
        for (int i = 0; i < N; i++)
        {
            cin >> b[i];
        }
        
        bool is_B2 = true;  
        
        // 1. 檢查第一個元素是否 < 1  
        if (b[0] < 1)
        {
            is_B2 = false;
        }
        
	    // 2. 檢查是否嚴格遞增
        for (int i = 1; i < N; i++)
        {
            if (b[i-1] > b[i])
            {
                is_B2 = false;
                break;
            }
        }
        
        // 3. 檢查兩兩之和是否唯一，若唯一會共有 1+2+...+N 個值
        int sum_list[1000000] = {0};
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = i; j < N; j++)
            {
                if (sum_list[b[i] + b[j]] == 0)
                {
                	sum_list[b[i] + b[j]]++; 
                	cnt++;
                }
            }
        }
        if (cnt != (N * (N + 1)) / 2)
        {
        	is_B2 = false;
        }        
        
        // 輸出
        if (is_B2 == true)
        {
            cout << "Case #" << n++ << ": It is a B2-Sequence.\n\n";
        }
        else
        {
            cout << "Case #" << n++ << ": It is not a B2-Sequence.\n\n";
        }
    }	
	
	return 0;
}