#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);	
	}
}

int main()
{
    adhamet;
	setIO("censor");
    string s, t;   cin >> s >> t;

    string censored;
    for(size_t i = 0; i < s.size(); i++) {
        censored += s[i];
        if (censored.size() > t.size() &&
            censored.substr(censored.size() - t.size()) == t) {
                censored.resize(censored.size() - t.size());
            }
    }
    cout << censored;
    
    return 0;
}
