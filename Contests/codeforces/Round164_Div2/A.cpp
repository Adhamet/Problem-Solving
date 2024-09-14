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
	int t;	scanf("%d", &t);
	while(t--) {
		int n,m,k;	cin >> n >> m >> k;
		if(n<=k || m==1) {
			printf("NO\n");
			continue;
		}

		if(ceil(n/m)==k) printf("NO\n"); // 5 2 1	
		else printf("YES\n");
	}
	
    return 0;
}