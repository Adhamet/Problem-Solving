#include <bits/stdc++.h>
using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define F first
#define S second
#define el '\n'

int sumOfDigits(int num) {
    int res = 0;
    while(num > 0) {
        res += num % 10;
        num /= 10;
    }
    return res;
}

void solve() {
    int arrN, q;
    cin >> arrN >> q;
    vector<int> vec(arrN);
    for(int i = 0; i < arrN; i++) cin >> vec[i];

    set<int> alive;
    for(int i = 0; i < arrN; i++) if(vec[i] > 9) alive.insert(i);

    int query,l,r,idx;
    while(q--) {
        cin >> query;
        if(query == 1) {
            cin >> l >> r;
            l--, r--;
            auto it = alive.lower_bound(l);
            while(it != alive.end() && *it <= r) {
                int pos = *it;
                vec[pos] = sumOfDigits(vec[pos]);
                auto nxt = next(it);
                if(vec[pos] <= 9) alive.erase(it);
                it = nxt;
            }
        } else {
            cin >> idx;
            cout << vec[idx-1] << el;
        }
    }
}

int main() {
    adhamet
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
