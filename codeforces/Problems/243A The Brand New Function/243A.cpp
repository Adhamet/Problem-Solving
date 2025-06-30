#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el  '\n'

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    static vector<char> seen(1<<20);
    vector<int> cur, nxt;
    cur.reserve(25);
    nxt.reserve(25);

    for(int i = 0; i < n; i++){
        nxt.clear();

        nxt.push_back(a[i]);
        for(int& x: cur){
            int y = x | a[i];
            if(nxt.back() != y) nxt.push_back(y);
        }

        for(int& v: nxt) seen[v] = 1;
        cur.swap(nxt);
    }

    i64 ans = 0;
    for(char c: seen) ans += c;
    return cout << ans, 0;
}
