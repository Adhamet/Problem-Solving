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
    setIO("mixmilk");

    vector<int> cap(3), currMilk(3);

    for(int i = 0; i < 3; i++) 
    	cin >> cap[i] >> currMilk[i];

    for(int i = 1; i <= 100; i++) {
    	int j = i % 3;
    	int milkMoved = min(currMilk[(j+2)%3], cap[j]-currMilk[j]);
    	currMilk[j] += milkMoved;
    	currMilk[(j+2)%3] -= milkMoved;
    }
	for(int i = 0; i < 3; i++) {
		cout << currMilk[i] << el;
	}

    return 0;
}