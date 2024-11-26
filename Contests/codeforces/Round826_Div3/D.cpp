#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

const int MAXN = 262144 + 5;
int cnt;
vector<int> a(MAXN);
void mergeSort(int n, int l, int r) {
	if (l == r) return;
	
	ll mid = (l + r) / 2;
	mergeSort(n, l, mid);
	mergeSort(n, mid + 1, r);
	
	if (a[l] > a[mid + 1]) {
		cnt += 1;
		int i = l, j = mid + 1;
		while (i < mid + 1) swap(a[i++], a[j++]);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
	
		cnt = 0;
		mergeSort(n, 0, n - 1);
		
		if (is_sorted(a.begin(), a.begin() + n)) cout << cnt << el;
		else cout << -1 << el;
	}

	return 0;
}
