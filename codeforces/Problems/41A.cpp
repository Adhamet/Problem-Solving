#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string str1,str2;
    cin >> str1 >> str2;
    reverse(str1.begin(), str1.end());
    if ( str1 == str2 )
        cout << "YES";
    else cout << "NO";
}
