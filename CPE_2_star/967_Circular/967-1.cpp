#include <cstdio>
#include <cstring>

#define MAX 1000001

bool prime[MAX];
int count_circular_prime[MAX];

void sieve()
{
    memset(prime, true, sizeof(prime));
    
    prime[0] = false;
    prime[1] = false;
    
    for (int i = 2; i * i < MAX; i++)
    {
        if (prime[i])
        {
            for (int j = i; i * j < MAX; j++)
            {
                prime[i * j] = false;
            }
        }
    }
}

int countDigits(int n)
{
    if (n == 0) return 1;
    
    int count = 0;
    while (n > 0)
    {
        count++;
        n /= 10;
    }
    
    return count;
}

int rotateOnce(int n, int digits, int divisor)
{
    int firstDigit = n / divisor;
    int remaining = n % divisor;
    
    return remaining * 10 + firstDigit;
}

bool check_circular(int x)
{
    if (!prime[x]) return false;
    
    int digits = countDigits(x);
    
    int divisor = 1;
    for (int i = 1; i <= digits - 1; i++)
    {
        divisor *= 10;
    }
    
    int current = x;
    
    for (int i = 1; i <= digits - 1; i++)
    {
        current = rotateOnce(current, digits, divisor);
        if (!prime[current])
        {
            return false;
        }
    }
    
    return true;
}

void countCircularPrimesUpTo()
{
    count_circular_prime[0] = 0;
    
    for (int i = 1; i < MAX; i++)
    {
        count_circular_prime[i] = count_circular_prime[i - 1];
        
        if (check_circular(i))
        {
            count_circular_prime[i]++;
        }
    }
}

int main()
{
    sieve();
    countCircularPrimesUpTo();
    
    int first, second;
    
    while (scanf("%d", &first) == 1)
    {
        if (first == -1) break;
        scanf("%d", &second);
        
        int ans = count_circular_prime[second] - count_circular_prime[first - 1];
        
        if (ans == 0)
        {
            printf("No Circular Primes.\n");
        }
        else if (ans == 1)
        {
            printf("1 Circular Prime.\n");
        }
        else
        {
            printf("%d Circular Primes.\n", ans);
        }
    }
    
    return 0;
}