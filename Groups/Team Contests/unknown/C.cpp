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

int main()
{
    adhamet;

    int n,q,op;	cin >> n >> q;
    char letter;
    vector<char> arr[n][n];

    for(int i = 0; i < q; i++) {
    	cin >> op;
    	if(op == 0) // painting step
    	{ 
    		int x,y;
    		cin >> letter >> x >> y;
    		arr[x][y].push_back(letter); // [1,1] = {a,a}, [0,1] = {b,d},
            // [0,0] = {c,}
    	} 
    	else if(op == 1) // removing step
    	{ 
    		int x,y;	cin >> x >> y;
            if(arr[x][y].empty()) continue;

            arr[x][y].pop_back();
    	} 
    	else if(op == 2) // a query 
    	{ 
    		int x,y;
    		cin >> letter >> x >> y;
            int currCount = 0;
            arr[x][y].shrink_to_fit();
            for(auto item: arr[x][y]) if(item == letter)
                currCount++;
            if(currCount > arr[x][y].size()/2) cout << "yes" << el;
            else cout << "no" << el;
    	}
    }
	
    return 0;
}