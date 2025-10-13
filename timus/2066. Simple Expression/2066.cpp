#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int a,b,c;
	std::cin>>a>>b>>c;
	std::cout << std::min({a-b-c, a-b*c, a*b-c});
	
	return 0;
}
