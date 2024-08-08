#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pLL pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;

    int t;
    cin >> t;
    while(t--) {
        int n, op;
        cin >> n >> op;
        string s;   cin >> s;
        vi ind(op);  for(int &i: ind) cin >> i;
        string c;   cin >> c;

        set<int> u(ind.begin(), ind.end());
        vi sortedInd(u.begin(), u.end());
        sort(sortedInd.begin(), sortedInd.end());
        sort(c.begin(), c.end());

        map<int, char> choices;
        for (int i = 0; i < sortedInd.size(); i++) choices[sortedInd[i]] = c[i];
        for (auto ch: choices) s[ch.F - 1] = ch.S;
        cout << s << el;
    }

    return 0;
}

