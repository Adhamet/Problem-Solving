#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int32_t main() {
	int32_t tc;
	cin >> tc;

	while (tc--) {
		int32_t a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (b == 0 && a) {
			for (int32_t i = 0; i <= a; ++i) printf("%d", 0);
			printf("\n");
		} else if (b == 0 && c) {
			for (int32_t i = 0; i <= c; ++i) printf("%d", 1);
			printf("\n");
		} else {
			deque<int32_t> dq;

			bool isEven = false;
			if (b % 2 == 0) isEven = true, b -= 1;

			dq.push_back(0), dq.push_back(1), b -= 1;
			while (b--) {
				if (dq.back() == 0) dq.push_back(1);
				else dq.push_back(0);
			}

			while (c--) dq.push_back(1);
			if (isEven) dq.push_back(0);
			while (a--) dq.push_front(0);

			while (!dq.empty()) printf("%d", dq.front()), dq.pop_front();
			printf("\n");
		}
	}

	return 0;
}
