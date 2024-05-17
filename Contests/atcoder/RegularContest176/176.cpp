#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int n,q;
vector<int> sumR, sumC;
vector<vector<bool>> matrix;
bool solve(int row) {
	if(row == n) {
		bool accepted = true;
		for(int i = 0; i < n; i++) if(sumR[i] != q || sumC[i] != q)
			accepted = false;
		return accepted;
	}

	if(sum[row]>=q) return false;

	for(int col = 0; col < n; col++) {
		if(matrix[row][col] || sumR[col]) continue;
		matrix[row][col] = true;
		sumR[row]++, sumC[col]++;
		if(solve(row+1)) return true;
		matrix[row][col] = false;
		sumR[row]--, sumC[col]--;
	}

	return false;
}

int main()
{
	scanf("%d %d", &n, &q);
	
	sumR.resize(n,0);
	sumC.resize(n,0);
	matrix.resize(n, vector<bool>(n,0));

	for(int i = 0; i < q; i++) {
		int x,y;	scanf("%d %d", &x, &y);
		matrix[x-1][y-1] = true;
		sumR[x-1]++, sumC[y-1]++;
	};

	solve(0);

	for(int row = 0; row < n; row++) {
		for(int col = 0; col < n; col++) {
			cout << matrix[row][col] << " ";
		}
		cout << el;
	}
    return 0;
}