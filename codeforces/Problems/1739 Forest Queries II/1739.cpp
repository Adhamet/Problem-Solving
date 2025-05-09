#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MAXN = 1005;
int a[MAXN][MAXN], n;

int t[4*MAXN][4*MAXN];
void build_2(int v1, int tl1, int tr1, int v2, int tl2, int tr2) {
	if (tl2 == tr2) {
		if (tl1 == tr1) t[v1][v2] = a[tl1][tl2];
		else t[v1][v2] = t[v1*2][v2] + t[v1*2+1][v2];
	} else {
		int tm2 = (tl2 + tr2) >> 1;
		build_2(v1, tl1, tr1, 2*v2, tl2, tm2);
		build_2(v1, tl1, tr1, 2*v2+1, tm2+1, tr2);
		t[v1][v2] = t[v1][v2*2] + t[v1][v2*2+1];
	}
}

void build_1(int v1, int tl1, int tr1) {
	if (tl1 != tr1) {
		int tm1 = (tl1 + tr1) >> 1;
		build_1(v1*2, tl1, tm1);
		build_1(v1*2+1, tm1+1, tr1);
	}
	build_2(v1, tl1, tr1, 1, 0, n - 1);
}



int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];

	build_1(1, 0, n - 1);

	return 0;
}
