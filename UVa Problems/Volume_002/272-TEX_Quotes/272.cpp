#include<bits/stdc++.h>
using namespace std;

int32_t main() {
    string s;
    int n = 0;
    while(getline(cin, s)){
        for (char i : s) {
            if(i == '"' && (n%2 == 0)) {
                cout << "``";
                n++;
            }
            else if(i == '"' && (n%2 == 1)){
                cout << "''";
                n++;
            }
            else cout << i;
        }
        cout << endl;
    }
    return 0;
}
