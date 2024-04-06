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

const int n = 8;
vector<bool> col(n), diag_pos(2*n-1), diag_neg(2*n-1);
int values[n][n];	
ll sum;
void searchQ(int row, ll currSum) {
	if(row == n) {
		sum = max(sum, currSum);
		return;
	}

	for(int c = 0; c < 8; c++) {
		if(col[c] || diag_pos[row+c] || diag_neg[n - 1 - c + row]) continue;
		col[c] = diag_pos[row+c] = diag_neg[n - 1 - c + row] = 1;
		searchQ(row+1, currSum + values[row][c]);
		col[c] = diag_pos[row+c] = diag_neg[n - 1 - c + row] = 0;
	}
}

int main()
{
    adhamet;
    
    int n = 8;
    int t;	cin >> t;
    while(t--) {
    	col.clear(), diag_pos.clear(), diag_neg.clear();
    	memset(values, 0, sizeof values);
    	sum = 0;
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < n; j++) {
    			cin >> values[i][j];
    		}
    	}

    	searchQ(0, 0);
    	printf("%5lld\n", sum);
    }
	
    return 0;
}