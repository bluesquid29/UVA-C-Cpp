#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    while (getline(cin, a) && getline(cin, b))
    {
        multiset<char> set_A(a.begin(), a.end());
        multiset<char> set_B(b.begin(), b.end());

		for (char c : set_A)
		{
		    if (set_B.count(c))
		    {
		        cout << c;
		        set_B.erase(set_B.find(c));  // 只移除一個
		    }
		}
		cout << '\n';
	}

    return 0;
}