#include <cstdio>

int maxBalls[51];

void buildTable()
{
    maxBalls[1] = 1;
    
    for (int i = 2; i <= 50; i++)
    {
        int diff = 2 * ((i + 1) / 2);
        maxBalls[i] = maxBalls[i - 1] + diff;
    }
}

int main()
{
    buildTable();
    
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", maxBalls[n]);
    }
    
    return 0;
}