#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 105;
/*const int oo = 1e9 + 20;*/

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		
		string str;
		for (int i = 0; i < n; i++) str.push_back(vowels[i % 5]);
		sort(begin(str), end(str));

		for (int i = 0; i < n; i++) cout << str[i];
		cout << el;
	}


	return 0;
}
