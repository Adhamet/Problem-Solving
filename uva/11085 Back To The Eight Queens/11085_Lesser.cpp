// Worse solution.
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

struct pt{
	int x,y;
}; vector<pt> pts(8);

bool accepted(int x1, int y1, int x2, int y2) {
	return (x2!=x1 && y2!=y1 && y2-y1!=x2-x1);
}

bool valid(int x1, int y1, int x2, int y2) {
	return (x1>=0 && y1>=0 && x2<8 && y2<8);
}

int queens(int idx, int steps) {
	if(valid) {
		if(accepted) return steps;
		return min({
			queens(idx+1, steps++);
			queens(idx+2, steps++);
			queens(idx+3, steps++);
			queens(idx+4, steps++);
			queens(idx+5, steps++);
			queens(idx+6, steps++);
			queens(idx+7, steps++);
		});
	}
}

int main()
{
    adhamet;

    while(2--) {
    	for(int i = 0; i < 8; i++)
    		cin >> pts[i];
    	int steps = queens(0,0);
    	cout << steps;
    }
	
    return 0;
}
