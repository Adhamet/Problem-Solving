#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string seat;
	std::cin >> seat;

	int row = 0, i = 0;
	while (isdigit(seat[i])) row = row * 10 + (seat[i++] - '0');
	char c = seat[i];

	if (row >= 1 && row <= 2) {
		if (c == 'A' || c == 'D') std::cout << "window";
		else if (c == 'B' || c == 'C') std::cout << "aisle";
		else std::cout << "neither";
	} else if (row >= 3 && row <= 20) {
		if (c == 'A' || c == 'F') std::cout << "window";
		else if (c == 'B' || c == 'C' || c == 'D' || c == 'E') std::cout << "aisle";
		else std::cout << "neither";
	} else if (row >= 21 && row <= 65) {
		if (c == 'A' || c == 'K') std::cout << "window";
		else if (c == 'C' || c == 'D' || c == 'G' || c == 'H') std::cout << "aisle";
		else std::cout << "neither";
	} else std::cout << "neither";

	return 0;
}
