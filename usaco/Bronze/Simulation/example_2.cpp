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
	int n;	cin >> n;
	vector<pair<int,int>> vec(n);
	for(int i = 0; i < n; i++) cin >> vec[i].first;
	for(int i = 0; i < n; i++) cin >> vec[i].second;
	
	for(int i = 0; i < n; i++) {
		int amt = min(A[i], C[i+1] - A[i+1]);

		A[i] -= amt;
		A[i+1] += amt;
	}
	for(int i = 0; i < n; i++) cout << A[i] << " ";
	cout << '\n';

    return 0;
}