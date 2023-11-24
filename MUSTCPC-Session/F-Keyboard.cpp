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
	string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";
	
	char dir;	cin >> dir;
	string s;	cin >> s;
	int idx=0;
	for(int i = 0; i < s.size(); i++) {
		idx = keyboard.find(s[i]);
		if (dir == 'R') cout << keyboard[idx-1];
		else cout << keyboard[idx+1];
	}
	
    return 0;
}