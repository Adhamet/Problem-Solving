#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(nullptr);

	int a, b;
	while (cin >> a >> b) {
		int c = 0;
		for (int i = 0; i < 32; i++) 
			if (((a>>i) & 1) != ((b>>i) & 1)) c |= (1 << i);
		cout << c << el;
	}

	return 0;
}
