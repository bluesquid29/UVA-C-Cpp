#include <cstdio>
#include <cstring>

#define MAX 101

bool prime[MAX];

void sieve()
{
    // Initialize: assume all are prime
    memset(prime, true, sizeof(prime));

    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i * i < MAX; i++) 
    {
        if (prime[i]) // if i is still prime
        {
            for (int j = i; i * j < MAX; j++) 
            {
                prime[i * j] = false;
            }
        }
    }
}

int main()
{
    sieve();  
    
    for (int i = 0; i < MAX; i++) 
    {
        if (prime[i])
        {
            printf("%d\n", i); 
        }
    }

    return 0;
}
