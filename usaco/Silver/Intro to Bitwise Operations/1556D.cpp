#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int ask(string s, int a, int b) {
	cout << s << ' ' << a << ' ' << b << el;
	int res;
	cin >> res;
	return res;
}

int sum(int a, int b) { // (0-indexed);
	int and_ = ask("and", a+1, b+1);
	int or_ = ask("or", a+1, b+1);

	int xor_ = ~(a&b) & (a|b); // 1,0 = 1  or 0,1 = 1

	return 2*(and_) + xor_; // 2*(a&b) is carry but shifted <<.
}

int main()
{
 	int n,k;	cin >> n >> k;

 	int a_plus_b = sum(0,1);
 	int a_plus_c = sum(0,2);
 	int b_plus_c = sum(1,2);

 	vector<int> arr{(a_plus_b + a_plus_c - b_plus_c) / 2};
 	arr.push_back(a_plus_b - arr[0]);
 	arr.push_back(b_plus_c - arr[0]);

 	for(int i = 3; i < n; i++) {
 		arr.push_back(sum(i-1, i) - arr.back());
 	}

 	sort(arr.begin(), arr.end());
 	cout << "finish " << arr[k-1] << el;
	
    return 0;
}