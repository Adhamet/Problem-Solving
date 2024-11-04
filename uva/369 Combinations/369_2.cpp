#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define el '\n'
#define MOD 1000000007
using ll = long long;
using ull = unsigned long long;

ull gcd(int a, int b) {
	while (b) { a %= b, swap(a, b); }
	return a;
}

ull nCr(vector<ll> nume, vector<ll> denome) {
	for (int i = 0; i < nume.size(); i++) {
		for (int j = 0; j < denome.size(); j++) {
			ll g = gcd(nume[i], denome[j]);
			nume[i] /= g, denome[j] /= g;
		}
	}

	ull ans = 1;
	for (int i = 0; i < nume.size(); i++) ans *= nume[i];
	for (int i = 0; i < nume.size(); i++) ans /= denome[i];
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	ull n, r;
	while (cin >> n >> r && n && r) {
		vector<ll> numerator, denominator;
		for (ull i = 1; i <= n; i++) numerator.push_back(i);
		for (ull i = 1; i <= n - r; i++) denominator.push_back(i);
		for (ull i = 1; i <= r; i++) denominator.push_back(i);
		cout << n << " things taken " << r << " at a time is ";
		cout << nCr(numerator, denominator) << " exactly.\n";
	}
	
	return 0;
}
