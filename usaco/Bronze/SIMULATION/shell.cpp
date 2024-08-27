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
    // setIO("shell");

    int n;	cin >> n;

    vector<int> shell_at_pos(3);
    for(int i = 0; i < 3; i++) shell_at_pos[i] = i;
    vector<int> counter(3);
	for(int i = 0; i < n; i++) {
		int a,b,g;	cin >> a >> b >> g;
		a--, b--, g--;

		swap(shell_at_pos[a], shell_at_pos[b]);
		counter[shell_at_pos[g]]++;
	}
	cout << max({counter[0], counter[1], counter[2], -1, -2, 1});

    return 0;
}