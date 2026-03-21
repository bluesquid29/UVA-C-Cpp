#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int const MAX = 1'000'000;
vector<bool> is_prime(MAX + 1, true);

void sieve()
{
    is_prime[0] = false;
    is_prime[1] = false;
    
    for (int i = 2; i * i <= MAX; i++)
    {
        if (is_prime[i])
        {
            for (int j = i; i * j <= MAX; j++)  { is_prime[i * j] = false; }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	sieve();
	
	int N;
	while (cin >> N)
	{
		if (is_prime[N])
		{
			string s = to_string(N);
			reverse(s.begin(), s.end());
			int new_N = stoi(s);
			
			if (is_prime[new_N] and new_N != N)  { cout << N << " is emirp.\n"; }
			else                                 { cout << N << " is prime.\n"; }
		}
		else                                     { cout << N << " is not prime.\n"; }
	}
	
	return 0;
}
