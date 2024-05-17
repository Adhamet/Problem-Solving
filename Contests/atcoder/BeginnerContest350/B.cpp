#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
	adhamet;
	int teeth, q;
	cin >> teeth >> q;
	int t[q];
	vector<bool> place(teeth, true);

	int currTeeth = teeth;
	for(int i = 0; i < q; i++) {
		int x;	cin >> x;
		if(place[x]) {
			currTeeth -= 1;
			place[x] = false;
		}
		else {
			currTeeth += 1;
			place[x] = true;
		}
	}
	printf("%d", currTeeth);
    
	
    return 0;
}