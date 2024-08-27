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

	int n;	cin >> n;
	int arr[n];
	pair<int,int> sarri[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i]; // 4 2 3 3 2
		sarri[i].first = arr[i];
		sarri[i].second = i;
	}
	sort(sarri, sarri+n, greater<pair<int,int>>());
	// {4,0}, {3,2}, {3,3}. {2,1}, {2,4}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int currMax = 1;
		int l = sarri[i].second - 1; // 1
		int r = sarri[i].second + 1; // 3

		while(l >= 0 && arr[l] <= arr[l+1])
			currMax++, l--;
		while(r < n && arr[r] <= arr[r-1])
			currMax++, r++;
		ans = max(ans,currMax);
	}
	cout << ans;
	
    return 0;
}