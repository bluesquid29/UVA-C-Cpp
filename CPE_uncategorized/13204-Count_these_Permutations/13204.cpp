#include <cstdio>
#define MOD 1000000007

long long factorial[1000001];

int main() 
{
    factorial[0] = 1;
    for (int i = 1; i <= 1000000; ++i) 
    {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
    
    int n;
    while (scanf("%d", &n) == 1) 
    {
        long long result;
        
        if (n % 2 == 1) 
        {
            result = (factorial[(n - 1) / 2] * factorial[(n - 1) / 2]) % MOD;
            result = (result * n) % MOD;
        } 
        else 
        {
            result = (factorial[n / 2] * factorial[n / 2]) % MOD;
        }
        
        printf("%lld\n", result);
    }
    
    return 0;
}