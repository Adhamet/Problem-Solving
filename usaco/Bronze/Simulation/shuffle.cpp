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

void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);	
	}
}

int main()
{
    adhamet;
	setIO("shuffle");

    int n;  cin >> n;
    vector<int> shuffle(n);
    for (int &i : shuffle) { cin >> i; }
    vector<int> ids(n);
    for (int &i : ids) { cin >> i; }
    
    for(int i = 0; i < 3; i++) {
        vector<int> past_order(n);
        for(int j = 0; j < n; j++) {
            past_order[j] = ids[shuffle[j] - 1];
        }
        ids = past_order;
    }
    
    for (const int &i : ids) { cout << i << el; }
    
    return 0;
}