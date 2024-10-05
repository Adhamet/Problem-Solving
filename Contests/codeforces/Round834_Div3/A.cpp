#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	string mainS = "YesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYes";
	while (t--) {
		string s;
		cin >> s;

		size_t found = mainS.find(s);
		if (found != std::string::npos) {
			cout << "YES" << el;
		} else cout << "NO" << el;
	}

	return 0;
}
