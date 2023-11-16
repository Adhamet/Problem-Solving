#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

vector<ull> all(1100);
ull j = 0;

void solve()
{
	bool flag;
	for(ull i = 1; i <= 1e9; i++) {
		flag = true;
		ull num = i;
		while(num >= 10) { // 11
			if (num % 10 >= (num/10) % 10) {
				flag = false;
				break;
			}
			num /= 10;
		}
		if (flag) {
			all[j] = i;
			j++;
		}
	}
}

int main()
{
    adhamet;
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
	
	solve();
	int k;
	cin >> k;
	cout << all[k-1];
	cout << el;

    return 0;
}