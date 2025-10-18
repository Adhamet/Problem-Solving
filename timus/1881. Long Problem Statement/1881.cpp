#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int h,w,n;	std::cin >> h >> w >> n;
	int curLine = 1, curWidth = 0, curPage = 1;
	for (int i = 0; i < n; ++i) {
		std::string s;	std::cin >> s;
		if (curWidth + (int)s.size() > w) {
			curLine += 1;
			if (curLine > h) {
				curPage += 1;
				curLine = 1;
			}
			curWidth = (int)s.size() + (i != n - 1);
		} else curWidth += (int)s.size() + (i != n - 1);
	}

	return std::cout << curPage, 0;
}
