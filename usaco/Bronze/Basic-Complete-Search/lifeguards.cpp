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
    setIO("lifeguards");

    int n;	cin >> n;
    
    vector<pair<int,int>> shifts(n);
    int max_time=0;
    for(int i = 0; i < n; i++) {
    	int x,y;	cin >> x >> y;
    	shifts[i].first = x;
    	shifts[i].second = y;
    	max_time = max(max_time, shifts[i].second);
    }
    
    int time[1000];
    for(int i = 0; i < n; i++) {
    	for(int j = shifts[i].first; j < shifts[i].second; j++) {
    		time[j]++;
    	}
    }

    int max_covered=0;
    for(int i = 0; i < n; i++) {
    	int time_covered=0;
    	for(int t = 1; t <= 1000; t++) {
    		for(int j = 0; j < n; j++) {
    			if(j != i && shifts[j].first <= t && t < shifts[j].second) {
    				time_covered++;
    				break;
    			}
    		}
    	}
    	max_covered = max(max_covered, time_covered);
    }
    cout << max_covered;

    return 0;
}