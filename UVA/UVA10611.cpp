#include <bits/stdc++.h>
 
using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define F first
#define S second
#define el '\n'

vector<int> ladies;

int up(int num) {
	int lo = 0, hi = ladies.size() - 1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (ladies[mid] <= num) lo = mid + 1;
		else if (ladies[mid] > num) hi = mid - 1;
 	}
	if (lo >= ladies.size()) return -1;
	return ladies[lo];
}

int down(int num) {
	int lo = 0, hi = ladies.size() - 1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (ladies[mid] < num) lo = mid + 1;
		else if (ladies[mid] >= num) hi = mid - 1;
	}
	if (hi < 0) return -1;
	return ladies[hi];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N;
	cin >> N;
	ladies = vector<int>(N);
	for (int i = 0; i < N; i++) cin >> ladies[i];

	int Q;
	cin >> Q;
	int luchu;
	while (Q--) {
		cin >> luchu;
		int first = down(luchu);
		int second = up(luchu);
		
		if (first == -1) cout << "X";
		else cout << first;
		if (second == -1) cout << " X" << endl;
		else cout << " " << second << endl;
	}

	return 0;
}
