#include <bits/stdc++.h>
int main() {
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;
	int x = a * d - b * c;
	if (x < 0) x = -x;
	int y = (a * d > b * c) ? a * d: b * c;
	int _g = std::__gcd(x, y);
	return std::cout << x / _g << "/" << y / _g, 0;
}
