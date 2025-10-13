#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::vector<std::string> v;
	v.push_back({"abc"});
	v.push_back({"def"});
	v.push_back({"ghi"});
	v.push_back({"jkl"});
	v.push_back({"mno"});
	v.push_back({"pqr"});
	v.push_back({"stu"});
	v.push_back({"vwx"});
	v.push_back({"yz"});
	v.push_back({".,!"});
	v.push_back({" "});
	int n = (int)v.size();

	std::string input;
	std::getline(std::cin, input);
	int m = (int)input.size();

	int totAns = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			int ssz = (int)v[j].size(), curAns = 0;
			bool found = false;
			
			for (int k = 0; k < ssz; ++k) {
				if (input[i] == v[j][k]) {
					found = true;
					curAns = k + 1;
					break;
				}
			}

			if (found) {
				totAns += curAns;
				break;
			}
		}
	}
	
	return std::cout << totAns, 0;
}
