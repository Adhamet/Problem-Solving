#include <bits/stdc++.h>
#include <cctype>
using namespace std;

#define el '\n'
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);     cout.tie(0);

    int t;  cin >> t;
    while(t--) {
        int n;  cin >> n;
        string s;   cin >> s;

        bool acc = true;
        for(int i = 0; i < n-1; i++) {
            if(isdigit(s[i+1]) && isalpha(s[i])) { 
                acc = false;
                break; 
            }
            if(s[i] > s[i+1]) {
                acc = false;
                break;
            }
        }
        if (acc) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
