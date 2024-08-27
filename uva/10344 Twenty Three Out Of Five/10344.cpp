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

int arr[5];
bool solvable(int idx, int val) {
	// base case
	if(idx == 5) return val == 23;

	return (
		solvable(idx+1, val+arr[idx]) ||
		solvable(idx+1, val-arr[idx]) ||
		solvable(idx+1, val*arr[idx])
	);
}

int main()
{
	adhamet;

	while(true) {
		for(int i = 0; i < 5; i++) {
			cin >> arr[i];
		}

		if(arr[0]==0 && arr[1]==0 && arr[2]==0 && arr[3]==0 && arr[4]==0)
			break;

		bool valid = false;
		sort(arr, arr+5);
		do {
			if(solvable(1,arr[0])) {
				valid = true;
				break;
			}
		} while(next_permutation(arr, arr+5));
		
		if (valid) cout << "Possible\n";
		else cout << "Impossible\n";
	}

	return 0;
}
