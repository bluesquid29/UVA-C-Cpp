#include <cstdio>
#include <cstring>

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
        
        // Collect digits from 9 to 2
        int digits[100], cnt = 0;
        for (int d = 9; d >= 2; d--)
        {
            while (N % d == 0)
            {
                digits[cnt++] = d;
                N /= d;
            }
        }
        
        // If N > 1, impossible
        if (N > 1)
        {
            printf("-1\n");
            continue;
        }
        
        // Reverse the collected digits
        for (int i = cnt - 1; i >= 0; i--)
        {
            printf("%d", digits[i]);
        }
        printf("\n");
    }
    
    return 0;
}

/*
## Example Trace for N = 12

12 ÷ 9 → no
12 ÷ 8 → no
12 ÷ 7 → no
12 ÷ 6 → 12/6 = 2, collect 6
 2 ÷ 5 → no
 2 ÷ 4 → no
 2 ÷ 3 → no
 2 ÷ 2 → 2/2 = 1, collect 2

Collected: [6, 2]
Reverse: 2 × 6 = 12 ✓
Answer: 26
*/