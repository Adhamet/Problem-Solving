#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

vector<ll> calc(ll num) {
	vector<ll> numOfDivisors;
	for (int i = 1; i * i < num; i += 1) if (num % i == 0) {
		numOfDivisors.push_back(i);
		if (i != num / i) numOfDivisors.push_back(num / i);
	}

	sort(numOfDivisors.rbegin(), numOfDivisors.rend());
	return numOfDivisors;
}

bool hasSquareDivisor(ll x) {
	for (ll i = 2; i * i <= x; i++) {
		if (x % (i * i) == 0) return true;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	ll n;
	cin >> n;
	vector<ll> numOfDivisors = calc(n);

	for (ll divisor: numOfDivisors) {
		if (!hasSquareDivisor(divisor)) {
			cout << divisor;
			break;
		}
	}

	return 0;
}
