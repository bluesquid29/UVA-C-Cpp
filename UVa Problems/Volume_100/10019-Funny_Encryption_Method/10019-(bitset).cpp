#include <iostream>
#include <string>    // std::stoi, std::to_string
#include <bitset>
using namespace std;

int main()
{
	int T;  cin >> T;
	while (T--)
	{
		int N; cin >> N;
		
		// 十進位 -> 二進位：計算有幾個 1
		int b1 = bitset<32>(N).count();
		
		// 十進位 -> 字串 -> 十六進位 -> 二進位：計算有幾個 1
		N = stoi(to_string(N), nullptr, 16); 	
		int b2 = bitset<32>(N).count();
		
		cout << b1 << ' ' << b2 << '\n';
	}

	return 0;
}