#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int n;	
	bool is_first = true;
	while (cin >> n)
	{
		if (!is_first)  {cout << '\n';}  is_first = false;
		
		double r = (2.0*n - 1) / 2.0;
		
		vector<double> y(n + 1);
		y[0] = r;
		y[n] = 0;
		for (int i = 1; i < n; ++i)
		{
			y[i] = sqrt(r*r - i*i);
		}
		
		int cnt_A = 0;  // complete cell
		int cnt_B = 0;  // segment cell
		for (int i = 0; i < n; ++i)
		{
			cnt_A += floor(y[i+1]);
			cnt_B += ceil(y[i]) - floor(y[i+1]);
		}
			
		cout << "In the case n = " << n << ", " << 4 * cnt_B << " cells contain segments of the circle.\n";
		cout << "There are " << 4 * cnt_A << " cells completely contained in the circle.\n";	
	}
	
	return 0;
}
