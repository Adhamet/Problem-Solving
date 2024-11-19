#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(nullptr);

	int a, b, c = 0;
	while (cin >> a >> b) {
		bitset<32> aa(a), bb(b), cc;
		for (size_t i = 0; i < 32; i++) 
			if ((aa[i] == 1 && bb[i] == 0) || (aa[i] == 0 && bb[i] == 1)) cc[i] = 1;
		cout << cc.to_ulong() << el;
	}

	return 0;
}
