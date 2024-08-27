#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

bool noRepetition(ll num) {
    string numStr = to_string(num);
    sort(numStr.begin(), numStr.end());
    return unique(numStr.begin(), numStr.end()) == numStr.end();
}

bool isValid(ll num) {
    string numStr = to_string(num);
    return numStr.size() <= 10;
}

int main()
{
    adhamet;

    int t;  cin >> t;
    int lines = 0;
    while(t--) {
        lines++;
        if(lines > 1) cout << el;

        ll num;    cin >> num;
        vector<ll> pairs;
        ll s2 = 0;
        while(++s2) if(noRepetition(s2)) {
            ll s1 = num * s2;
            if(!isValid(s1)) break;
            else if(noRepetition(s1)) pairs.push_back(s2);
        }

        sort(pairs.begin(), pairs.end());
        for(ll s2: pairs) cout << num * s2 << " / " << s2 << " = " << num << el;
    }

    return 0;
}
