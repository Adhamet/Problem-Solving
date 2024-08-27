#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;	cin >> n;	
	set<int> distNumbers;

	for(int i = 0; i < n; i++) {
		int num;	cin >> num;
		distNumbers.insert(num);
	}
	
	cout << distNumbers.size() << '\n';

	return 0;
}
