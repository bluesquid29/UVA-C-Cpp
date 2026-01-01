#include <cstdio>

int main() 
{
    int n;
    while (scanf("%d", &n) == 1) 
    {
        if (n == 0) 
        {
            printf("0\n");
            continue;
        }
        int how_many_one = 1;
        int remainder = 1 % n;
        while (remainder != 0) 
        {
            remainder = (remainder * 10 + 1) % n;
            how_many_one++;
        }
        printf("%d\n", how_many_one);
    }
    return 0;
}