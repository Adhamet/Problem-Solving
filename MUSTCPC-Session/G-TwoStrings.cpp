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

int main()
{
    adhamet;
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
	int t;	cin >> t;
	while(t--) {
		string s1,s2;	cin >> s1 >> s2;
		unordered_set<char> s;

		for(int i = 0; i < s1.size(); i++) s.insert(s1[i]);

		bool flag = 0;
		for(int i = 0; i < s2.size(); i++) if(s.find(s2[i]) != s.end()) {
			flag = 1;
			break;
		}
		if (flag) cout << "YES" << el;
		else cout << "NO" << el;
	}
	
    return 0;
}