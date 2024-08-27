#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int process(vi &foo) {
	int len = foo.size();

	if (len == 0) {
		cout << "0\n";
	} else if (len == 1) {
		cout << "pushStack\n1 popStack\n";
	} else if (len == 2) {
		cout << "pushStack\npushQueue\n2 popStack popQueue\n";
	} else if (len == 3) {
		cout << "pushStack\npushQueue\npushFront\n3 popStack popQueue popFront\n";
	} else {
		vi bar = foo;
		sort(begin(bar), end(bar), [](auto &l, auto &r) {return l > r;});

		vi a(3,-1);
		for(int i = 0; i < len; i++) {
			for(int j = 0; j < 3; j++) {
				if(a[j] == -1 && foo[i] == bar[j]) {
					a[j] = i;
					break;
				}
			}
		}
		sort(begin(a), end(a));

		for(int i = 0; i < a[0]; i++) cout << "pushStack\n";
		cout << "pushQueue\n";
		for(int i = a[0]+1; i < a[1]; i++) cout << "pushStack\n";
		cout << "pushFront\n";
		for(int i = a[1]+1; i <= a[2]; i++) cout << "pushStack\n";
		for(int i = a[2]+1; i < len; i++) cout << "pushBack\n";
		cout << "3 popStack popQueue popFront\n";
	}
	
	return 0;
}

int main()	{
	adhamet;
	int n; cin >> n;
	vi jar(n); for(auto &x: jar) cin >> x;

	int beg = 0;
	for(int i = 0; i < n; i++) {
		if(jar[i] == 0) {
			vi foo = {begin(jar)+beg, begin(jar)+i};
			process(foo);
			beg = i + 1;
		}
	}

	for(int i = n - 1; i >= 0 && jar[i] != 0; i--) cout << "pushStack\n";
	return 0;
}

