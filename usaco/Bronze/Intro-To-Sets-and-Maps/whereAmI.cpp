#include <bits/stdc++.h>
using namespace std;
#define el '\n';

 void setIO(string name = "") {
     if (name.size()) {
         freopen((name+".in").c_str(), "r", stdin);
         freopen((name+".out").c_str(), "w", stdout);
     }
}

int n;
string s;
bool solve(int p) {
    set<string> st;
    for(int i = 0; i < n; i++) {
        if(st.count(s.substr(i,p))) return false;
        else st.insert(s.substr(i,p));
    }
    return true;
}

int main() 
{
    ios_base::sync_with_stdio(0);   cin.tie(0);     cout.tie(0);
    setIO("whereami");

    cin >> n >> s;
    for(int i = 1; i <= n; i++) {
        bool flag = solve(i);
        if(flag) {
            cout << i << el;
            break;
        }
    }

    return 0;
}
