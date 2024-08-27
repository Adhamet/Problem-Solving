// EASY IN RECURSION, MEDIUM IN DETERMINING THE REST.
#include <bits/stdc++.h>
using namespace std;

#define adhamet ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define ull unsigned long long
#define el '\n'
void setIO(string name = "");
void redirectIO();

ll ans = 0;
vector<ll> hand, p;
bool accepted = true;
ll calc(int op, ll x, ll y) {
    if(op == 0) return x+y;
    else if(op == 1) return x-y;
    else if(op == 2) return x*y;
    else if(op == 3 && x!=0 && y!=0 && x%y==0) return x/y;
    accepted = false;
    return (ll)0;
}

ll solve(int idx) {
    if(idx >= 4) {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                for(int k = 0; j < 4; j++) {
                    accepted = true;
                    ll res = calc(k, calc(i, p[0], p[1]), calc(j, p[2], p[3]));
                    if(accepted && res <= 24) ans = max(ans, res);

                    accepted = true;
                    res = calc(k, calc(j, calc(i, p[0], p[1]), p[2]), p[3]);
                    if(accepted && res <= 24) ans = max(ans, res);
                }
            }
       }
        return 0;
    }

    for(int i = 0; i < 4; i++) if(hand[i] != 0) {
        ll temp = hand[i];

        p.push_back(hand[i]);
        hand[i] = 0;
        solve(idx+1);
        hand[i] = temp;
        p.pop_back();
    }
    return 0;
}

int main()
{
    adhamet

    int t;  cin >> t;
    while(t--) {
        hand.clear();
        hand.resize(4);
        ans = 0;

        for(int i = 0; i < 4; i++) cin >> hand[i];

        solve(0);
        cout << ans << el;
    }

    return 0;
}

//void setIO(string name) {
//    if (!name.empty()) {
//        freopen((name + ".in").c_str(), "r", stdin);
//        freopen((name + ".out").c_str(), "w", stdout);
//    }
//}

//void redirectIO() {
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
//        freopen("errors.txt", "w", stderr);
//    #endif
//}
