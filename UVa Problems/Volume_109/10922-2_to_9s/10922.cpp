#include <iostream>
#include <string>
using namespace std;

int Digit_Sum(int n)
{
    int sum = 0;
    while (n > 0)
    { 
    	sum += n % 10;
    	n /= 10; 
    }
    
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);  cin.tie(nullptr);

    string s;
    while (cin >> s and s != "0")
    {
        // 第一次：字串直接求位數和（處理大數），即可判斷是否為 9 的倍數
        int sum = 0;
        for (char c : s)  { sum += c - '0'; }

        if (sum % 9 != 0)
        {
            cout << s << " is not a multiple of 9.\n";
            continue;
        }

        // 計算 9-degree
        int degree = 1;
        while (sum >= 10)
        { 
        	sum = Digit_Sum(sum);  
        	degree++; 
        }

        cout << s << " is a multiple of 9 and has 9-degree " << degree << ".\n";
    }

    return 0;
}