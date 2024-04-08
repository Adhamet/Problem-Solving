
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
 
    int n,a,b,d;	cin >> n >> a >> b >> d;

    vector<int> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];

    a -= d;
    b += d;
 
    vector<int> ans;
 	for(int i = 0; i < vec.size(); i++)
 		if(vec[i] >= a && vec[i] <= b)
    		ans.push_back(i);
    if(!ans.empty()) for(auto itm: ans) cout << itm << " ";
   	else cout << "";
 
    return 0;
}