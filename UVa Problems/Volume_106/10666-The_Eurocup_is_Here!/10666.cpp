#include <cstdio>

int main() 
{
    int T;
    scanf("%d", &T);
    
    while (T--) 
    {
        int N, X;
        scanf("%d %d", &N, &X);
        
        // team 0 never lost, champion
        if (X == 0) 
        {
            printf("1 1\n");
            continue;
        }
        
        // Count trailing zeros (consecutive wins)
        int win = 0;
        while (X > 0 && (X & 1) == 0) 
        {
            win++;
            X >>= 1;
        }
        
        // Count total 1-bits after removing trailing zeros (total losses)
        int loss = 0;
        while (X > 0) 
        {
            if (X & 1) 
            {
                loss++;
            }
            X >>= 1;
        }
        
        int optimistic = 1 + loss;
        int pessimistic = (1 << N) - (1 << win) + 1;
        
        printf("%d %d\n", optimistic, pessimistic);
    }
    
    return 0;
}