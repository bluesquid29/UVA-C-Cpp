#include <iostream>
using namespace std;

int level = 0;

void New_Taiwan_Dollar(long long n)
{
	if (n >= 10000)
	{
		level++;
		New_Taiwan_Dollar(n/10000);
		n %= 10000;
	}
	if (n >= 1000)
	{
		cout << " " << n/1000 << " 千";
		n %= 1000;
	}
	if (n >= 100)
	{
		cout << " " << n/100 << " 百";
		n %= 100;
	}
	if (n >= 10)
	{
		cout << " " << n/10 << " 十";
		n %= 10;
	}
	if (n > 0)
		cout << " " << n;
		
	switch (level)
	{
		case 4:
			level--;		
			cout << " 京";
			break;
		case 3:
			level--;		
			cout << " 兆";
			break;
		case 2:
			cout << " 億";
			level--;
			break;
		case 1:
			cout << " 萬";
			level--;
			break;
	}
	return;
}
    	
int main()
{
    long long  n;
    while (cin >> n)
    {
    	New_Taiwan_Dollar(n);
	    cout << '\n';	
    }

	return 0;
}