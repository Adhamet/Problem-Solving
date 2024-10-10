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
    setIO("lostcow");

    int farmer, bessie;     cin >> farmer >> bessie;
    
    int distance = 0, prev = farmer, mul = 1;
    while(bessie != farmer) {
        int func = farmer + mul;
        if ( (bessie > farmer && bessie <= func) || (bessie < farmer && bessie >= func) ) {
            distance += abs(bessie - prev);
            break;
        }
        distance += abs(func - prev);
        prev = func;
        mul *= -2;
    }
    cout << distance;
    
    return 0;
}
