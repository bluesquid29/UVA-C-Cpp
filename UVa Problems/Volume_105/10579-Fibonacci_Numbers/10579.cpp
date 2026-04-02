#include <cstdio>

typedef unsigned int uint;

const uint BASE = 1000000000;  // 10^9 is the maximum

uint f[5001][120] = {0};

int main()
{
    f[1][0] = 1;
    for (int i = 2; i <= 5000; i++) 
    {
        for (int j = 0; j < 120; j++) 
        {
            uint sum = f[i-1][j] + f[i-2][j] + f[i][j];  
            f[i][j+1] += sum / BASE;
            f[i][j] = sum % BASE;
        }
    }
    
    int n;
    while (scanf("%d", &n) == 1)
    {
        // printf("The Fibonacci number for %d is ", n); UVA 495
        int j;
        for (j = 119; j >= 0; j--)
        {
            if (f[n][j])
            {
                break;
            }
        }
        
        if (j == -1)
        {
            printf("0");
        }
        else
        {
            printf("%d", f[n][j]);     // print with no zero in front
            for (j--; j >= 0; j--)
            {
                printf("%09d", f[n][j]); // XXXXXXXXX style
            }
        }
        printf("\n");
    }
    
    return 0;
}