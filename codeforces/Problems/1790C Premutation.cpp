#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

/*const int N = 20 + 5;*/
/*const int oo = 1e9 + 20;*/

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		
		vector<vector<int>> vecs(n, vector<int>(n - 1));
		unordered_map<int, int> freq;
		for (auto &vec: vecs) {
			for (auto &ele: vec) {
				cin >> ele;
			}

			freq[vec[0]] += 1;
		}

		int firstEle = -1, mx = 0;
		for (auto &f: freq) if (mx < f.second) {
			mx = f.second, firstEle = f.first;
		}
		
		cout << firstEle << " ";
		for (int i = 0; i < n; i++) if (vecs[i][0] != firstEle) {
			for (int j = 0; j < n - 1; j++) cout << vecs[i][j] << " "; 
			break; 
		}
		cout << endl;
	}
}
