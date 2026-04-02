#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	string country;
	string name;
	map<string, int> mp;
	
	int T;  cin >> T;
	while (T--)
	{
		cin >> country;
		getline(cin, name);
		
		mp[country]++;
	}
	
	for (auto& [a, b] : mp)
	{
		cout << a << ' ' << b << '\n';
	}
	
	return 0;
}
