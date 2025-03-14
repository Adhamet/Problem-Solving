#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int MAXN = 1e5+5;
int32_t n, a[MAXN], memo[MAXN];

bool solve(int32_t idx) {
	if (~memo[idx]) return memo[idx];
	bool acc = 0;
	for (int j = idx - a[idx]; j >= 0; j -= a[idx])
		if (a[idx] < a[j]) acc |= !solve(j);
	for (int j = idx + a[idx]; j < n; j += a[idx])
		if (a[idx] < a[j]) acc |= !solve(j);
	return memo[idx] = acc;
}

int32_t main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i) memo[i] = -1;
	for (int i = 0; i < n; ++i) {
		bool acc = solve(i);
		cout << (acc? "A": "B");
	}
}
