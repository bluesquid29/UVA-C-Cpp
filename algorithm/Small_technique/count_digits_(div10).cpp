#include <cstdio>

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

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", countDigits(n));
	
	return 0;	
}

/*
The problem: 
`int` can only reliably hold values up to about (2^31 - 1 = 2,147,483,647), 
which is 10 digits. 

However, `long long` can hold values up to about (2^63 - 1 = 9,223,372,036,854,775,807), 
which is 19 digits.

I'm not sure why `long` holds same value (19 digit) in CP Editor.
*/