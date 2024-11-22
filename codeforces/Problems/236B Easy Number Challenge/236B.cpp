#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'
#define MOD 1073741824

vector<ll> divz(ll num) {
	vector<ll> divisors(num + 1, 0);
	for (int i = 1; i <= num; i++) {
		for (int j = i; j <= num; j += i) {
			divisors[j] += 1;
		}
	}

	return divisors;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;

	int MAXN = ((((a * b) % MOD) * c) % MOD);
	vector<ll> divisors = divz(MAXN);

	ll sum = 0;
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			for (int k = 1; k <= c; k++) {
				ll num = ((((i * j) % MOD) * k) % MOD);
				sum = (sum + divisors[num]) % MOD;
			}
		}
	}

	cout << sum;
	return 0;
}
