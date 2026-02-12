#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int m;
    int T = 1; // Test cases
    bool is_first = true;
    
    while(cin >> n >> m)
    {
    	if (n == 0 && m == 0)  break;
		if (!is_first)  cout << endl;
		is_first = false;
        
        cout << "Field #" << T++ << ":" << endl;
        
	    map<int, map<int, int>> field;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> field[i][j];
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(field[i][j] == '*')
                {
                    cout << "*";
                }
                else
                {
 			        int goal = 0;
                    goal = (field[i-1][j-1] == '*') +
                           (field[i-1][j  ] == '*') +
                           (field[i-1][j+1] == '*') +
                           (field[i  ][j-1] == '*') +
                           (field[i  ][j+1] == '*') +
                           (field[i+1][j-1] == '*') +
                           (field[i+1][j  ] == '*') +
                           (field[i+1][j+1] == '*');
                    cout << goal;
                }
            }
            cout << endl;
        }
    }
    
    return 0;
}