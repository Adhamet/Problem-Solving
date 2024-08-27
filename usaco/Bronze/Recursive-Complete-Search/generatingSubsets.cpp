#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

/* Bitmasking Method */
int main()
{
	adhamet;

	int n=3;

	for (int b = 0; b < (1<<n); b++) {
		vector<int> subset;
		for (int i = 0; i < n; i++) {
			if (b&(1<<i)) subset.push_back(i);
		}
		for(int elem: subset)
			cout << elem << " ";
		cout << el;
	}

	return 0;
}

/* Recursive method:
const int n = 3;
vector<int> subset;

void processSubset() {
	cout << "Subset: ";
	for(const auto& ele: subset)
		cout << ele << " ";
	cout << el;
}

int search(int k) {
	if(k == n) {
		processSubset();
	} else {
		search(k+1);
		subset.push_back(k);
		search(k+1);
		subset.pop_back();
	}
}

int main()
{
    adhamet;

    search(0);

    return 0;
} */