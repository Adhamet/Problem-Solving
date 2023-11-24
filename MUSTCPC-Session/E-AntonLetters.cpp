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
	string s;	getline(cin, s);
	set<char> st;

	for(int i = 0; i < s.size(); i++) {
		if (s[i] == '{' || s[i] == '}' || s[i] == ',' || s[i] == ' ') continue;
		st.insert(s[i]);
	}
	cout << st.size();
	
    return 0;
}