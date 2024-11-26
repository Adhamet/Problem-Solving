#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s, t;
		cin >> s >> t;
		char typeS = s.back();
		char typeT = t.back();

		if (typeS == typeT) {
			int countX_S = count(s.begin(), s.end(), 'X');
            int countX_T = count(t.begin(), t.end(), 'X');

			if (typeS == 'S') {
                if (countX_S < countX_T) cout << ">" << '\n';
                else if (countX_S > countX_T) cout << "<" << '\n';
                else cout << "=" << '\n';
            } else if (typeS == 'L') {
                if (countX_S > countX_T) cout << ">" << '\n';
                else if (countX_S < countX_T) cout << "<" << '\n';
                else cout << "=" << '\n';
            } else cout << "=" << '\n';
        } else {
            if ((typeS == 'S') || (typeS == 'M' && typeT == 'L')) cout << "<" << '\n';
            else cout << ">" << '\n';
        }
	}

	return 0;
}
