#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int n, m, minMoney = 1e9;
vector<bool> used;
struct COW {
	int a, b, c;
} cows[20];
struct AC {
	int a, b, c, m;
} ac[10];

void solve(int idx, int money) {
	if(idx == m) {
		bool accepted = true;
		for(int i = 1; i <= 100; i++) {
			
			int cooling = 0;
			for(int j = 0; j < m; j++) {
				if(!used[j]) continue;
				if(ac[j].a <= i && i <= ac[j].b) cooling += ac[j].c;
			}

			int cowReq = 0;
			for(int j = 0; j < n; j++) if(cows[j].a <= i && i <= cows[j].b) {
				cowReq = cows[j].c;
				break;
			}

			if(cooling < cowReq) {
				accepted = false;
				break;
			}
		}

		if(accepted) minMoney = min(minMoney, money);

		return;
	}

	
	used[idx] = false;
	solve(idx+1, money);
	used[idx] = true;
	solve(idx+1, money + ac[idx].m);
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%d %d %d", &cows[i].a, &cows[i].b, &cows[i].c);
	for(int i = 0; i < m; i++) scanf("%d %d %d %d", &ac[i].a, &ac[i].b, &ac[i].c, &ac[i].m);
	
	used.assign(m, false);
	solve(0,0);

	printf("%d", minMoney);

    return 0;
}
