#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);   cin.tie(0);    cout.tie(0);
    int q;  cin >> q;
    map<long long,long long> a;

    while(q--) {
        int op;  cin >> op;
        long long k,v; cin >> k;

        if(op) cout << a[k] << '\n';
        else { cin >> v;    a[k] = v; }
    }

    return 0;
}
