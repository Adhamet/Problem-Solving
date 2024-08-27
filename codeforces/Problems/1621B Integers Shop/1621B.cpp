#include <bits/stdc++.h>
using namespace std;

#define el '\n';
#define ll long long;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;  cin >> t;
    while(t--) {
        int n;  cin >> n;

        int l = INT_MAX, r = 0;
        int cl = INT_MAX, cr = INT_MAX, ans = INT_MAX;

        for(int i = 1; i <= n; i++) {
            int li,ri,ci;   cin >> li >> ri >> ci;

            if(l > li) { l = li;    cl = ci;    ans = INT_MAX; }
            else if(l == li) { cl = min(cl, ci); }

            if(r < ri) { r = ri;    cr = ci;    ans = INT_MAX; }
            else if(r == ri) { cr = min(cr, ci); }

            if(l == li && r == ri) { ans = min(ans, ci); }

            cout << min(ans, cl+cr) << el;
        }
    }
}
