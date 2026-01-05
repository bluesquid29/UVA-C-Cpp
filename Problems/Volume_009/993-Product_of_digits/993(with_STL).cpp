#include <cstdio>
#include <vector>
#include <algorithm>

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        int N;
        scanf("%d", &N);
        
        if (N < 10)
        {
            printf("%d\n", N);
            continue;
        }
        
        std::vector<int> digits;
        for (int d = 9; d >= 2; d--)
        {
            while (N % d == 0)
            {
                digits.push_back(d);
                N /= d;
            }
        }
        
        if (N > 1)
        {
            printf("-1\n");
            continue;
        }
        
        std::reverse(digits.begin(), digits.end());
        
        for (int x : digits)
        {
            printf("%d", x);
        }
        printf("\n");
    }
    
    return 0;
}