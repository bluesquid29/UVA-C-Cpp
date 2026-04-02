#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
    int n;  cin >> n;

    for (int i = 0; i < (1 << n); ++i)
    {
        int gray = i ^ (i >> 1);
        for (int k = n - 1; k >= 0; k--)  { cout << ((gray >> k) & 1); }
        cout << '\n';
    }

    return 0;
}
