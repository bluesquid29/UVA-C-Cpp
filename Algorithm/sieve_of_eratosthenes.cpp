#include <cstdio>

#define MAX 10001

int prime[MAX];

void sieve()
{
    // Initialize: assume all are prime
    for (int i = 0; i < MAX; i++)  
    {
        prime[i] = true;
    }

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
    
    for (int i = 2; i < MAX; i++) 
    {
        if (prime[i])
        {
            printf("%d\n", i); 
        }
    }
    printf("\n"); 
    
    return 0;
}
