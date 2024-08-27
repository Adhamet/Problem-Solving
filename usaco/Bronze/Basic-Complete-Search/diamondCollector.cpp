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
    setIO("diamond");

    int n,k;	cin >> n >> k; // 5,3
    int diamonds[n];
    for(int i = 0; i < n; i++) cin >> diamonds[i]; // 1,6,4,3,1
    sort(diamonds,diamonds+n);

    int maxSeq=1,sequence=1;
    for(int i = 0; i < n-1; i++) {
    	sequence=1;
    	for(int j = i+1; j < n; j++)
	    	if(abs(diamonds[j]-diamonds[i])<=k)
	    		sequence++;
	    maxSeq=max(maxSeq,sequence);
    }
    cout << maxSeq;
	
    return 0;
}