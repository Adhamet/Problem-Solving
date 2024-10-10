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
	setIO("cbarn");

    int n;  cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    // O(n^2)
    int minTotalDist=1e9;
    for(int i = 0; i < n; i++) {
        int minCurrDist=0;
        int currLoop=n-i, j=1;
        
        // Loop up from i to the end of the array
        while(--currLoop) {
            minCurrDist+=arr[i+j]*j;
            j++;
        }
        // Loop from the start of the array to i
        int upToIdx = 0;
        while(upToIdx<i) {
            minCurrDist+=arr[upToIdx]*j;
            upToIdx++;
            j++;
        }
        
        // Calculate the minimum total distance
        minTotalDist=min(minTotalDist,minCurrDist);
    }
    cout << minTotalDist << el;
    
    return 0;
}
