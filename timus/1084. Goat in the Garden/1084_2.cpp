#include <bits/stdc++.h>

#define PI acos(-1)
using i64 = long long;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout << std::fixed << std::setprecision(3);
	
	double s, r;
	std::cin >> s >> r;
	
	double a = (s / 2.0);
	if (r <= a) {
		std::cout << PI * r * r << '\n';
	} else if (r >= a * sqrt(2.0)) {
		std::cout << s * s << '\n';
	} else {
		double thytaRad = 2 * acos(a / r);
		double areaOfCircle = PI * r * r;
		double areaOfCircSeg = (r * r / 2) * (thytaRad - std::sin(thytaRad));
		double area = areaOfCircle - 4 * areaOfCircSeg;
		std::cout << area << '\n';
	}

	return 0;
}

