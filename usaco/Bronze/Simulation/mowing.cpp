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
	setIO("mowing");
    
    int n;  cin >> n;
    int time = 1;
    map<pair<int,int>, int> visit{{ {0,0}, 0 }};
    vector<int> savedTimes;

    int x=0,y=0;
    for(int i = 0; i < n; i++) {
        bool up=0,down=0,left=0,right=0;

        char D;
        int S;
        cin >> D >> S;

        if (D=='N') up=1;
        else if(D=='S') down=1;
        else if(D=='E') right=1;
        else if(D=='W') left=1;

        for(int j = 0; j < S; j++) {
            if(up) x+=1;
            else if(down) x-=1;
            else if(right) y+=1;
            else if(left) y-=1;

            if(visit[{x,y}] != 0) {
                savedTimes.push_back(time - visit[{x,y}]);
            }
            visit[{x,y}] = time;
            time++;
        }
    }

    int mn = INT_MAX;
    for(const auto &itm: savedTimes){
        mn = min(mn, itm);
    }
    cout << (mn == INT_MAX ? -1 : mn);

    return 0;
}