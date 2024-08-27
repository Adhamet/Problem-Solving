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
	int fs,rs;
	while(scanf("%d", &fs) && fs) {
		scanf("%d", &rs);
		double f[12], r[12], drive[105];
		for(int i = 0; i < fs; i++) scanf("%lf", &f[i]);
		for(int i = 0; i < rs; i++) scanf("%lf", &r[i]);

		int k = 0;
		for(int i = 0; i < rs; i++)
			for(int j = 0; j < fs; j++)
				drive[k++] = r[i] / f[j];
		sort(drive, drive+k);

		double mxSpread = 0;
		for(int i = 0; i < k-1; i++)
			mxSpread = max(mxSpread, drive[i+1]/drive[i]);

		printf("%.2lf\n", mxSpread);
	}

    return 0;
}

