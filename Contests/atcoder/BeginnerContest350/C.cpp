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
    
    int n;	scanf("%d",&n);
    int perm[n], id[n];

    vector<pair<int,int>> ans;
    for(int i = 1; i <= n; i++) scanf("%d", &perm[i]), id[perm[i]] = i;

    for(int i = 1; i<=n; i++) if(perm[i] != i)
    	ans.push_back({i,id[i]}), id[perm[i]] = id[i], swap(perm[i], perm[id[i]]);

    printf("%d\n", (int)ans.size());
    for(auto [i,j]: ans) printf("%d %d\n", i, j);
	
    return 0;
}