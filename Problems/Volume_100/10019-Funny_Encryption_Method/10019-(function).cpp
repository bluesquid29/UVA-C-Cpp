#include <iostream>
using namespace std;

int Dec_to_Bin(int N)
{	
	int b1 = 0;
	while (N > 0)
	{
		if (N % 2 == 1)  { b1++; }
		N /= 2;
	}
	
	return b1;
}

int Hex_to_Bin(int N)
{	
	int b2 = 0;
	while (N > 0)
	{
		b2 += Dec_to_Bin(N % 10);
		N /= 10;
	}
	
	return b2;
}

int main()
{
	int T;  cin >> T;
	while (T--)
	{
		int N; cin >> N;
		cout << Dec_to_Bin(N) << ' ' << Hex_to_Bin(N) << '\n'; 
	}

	return 0;
}
