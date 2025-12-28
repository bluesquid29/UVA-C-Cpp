#include <cstdio>

int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int main() 
{
    int N;
    
    while (scanf("%d", &N) == 1 && N != 0) 
    {
        printf("%3d! =", N);
        
        int column = 0;
        for (int i = 0; i < 25 && primes[i] <= N; i++) 
        {
            if (column > 0 && column % 15 == 0) 
            {
                printf("\n      ");
            }
            
            int exponent = 0;
            int temp = N;
            while (temp > 0) 
            {
                temp /= primes[i];
                exponent += temp;
            }
            
            printf("%3d", exponent);
            column++;
        }
        printf("\n");
    }
    
    return 0;
}