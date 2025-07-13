#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

constexpr int MXN = 85;
string s, t;
int mem[MXN][MXN];

int editDist(int i, int j) {
	if (i == (int)s.size())
		return (int)t.size() - j;
	if (j == (int)t.size())
		return (int)s.size() - i;

	int &ret = mem[i][j];
	if (~ret) return ret;
	ret = 200;

	if (s[i] == t[j]) ret = min(ret, editDist(i+1, j+1));
	else {
		ret = min(ret, 1 + editDist(i, j + 1)); // insert
		ret = min(ret, 1 + editDist(i + 1, j)); // delete
		ret = min(ret, 1 + editDist(i + 1, j + 1)); // replace
	}

	return ret;
}

int op = 0;
int idxShift = 0;
void traceED(int i, int j) {
	if (i == (int)s.size()) {
		int toAdd = (int)t.size() - j;
		int k = 0;
		while (k < toAdd) {
			cout << ++op << " Insert " << i+1+idxShift << ',' << t[j+k] << el;
			/*cout.flush();*/
			idxShift++, ++k;
		}

		return;
	}

	if (j == (int)t.size()) {
		int toDel = (int)s.size() - i;
		int k = 0;
		while (k < toDel) {
			cout << ++op << " Delete " << i+1+idxShift << el;
			/*cout.flush();*/
			idxShift--, ++k;
		}

		return;
	}

	if (s[i] == t[j]) {
		traceED(i+1, j+1);
		return;
	}

	int ins  = 1 + editDist(i,   j+1);
	int del  = 1 + editDist(i+1, j);
	int rep  = 1 + editDist(i+1, j+1);

	int best = editDist(i, j);
	if (best == rep) {
		cout << ++op << " Replace " << (i+1+idxShift) << ',' << t[j] << el;
		traceED(i+1, j+1);
	} else if (best == del) {
		cout << ++op << " Delete " << (i+1+idxShift) << el;
		--idxShift;
		traceED(i+1, j);
	} else {
		cout << ++op << " Insert " << (i+1+idxShift) << ',' << t[j] << el;
		++idxShift;
		traceED(i,j+1);
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	bool fst = true;
	while (getline(cin, s) && getline(cin, t)) {
		if (!fst) cout << el;
		fst = false;

		memset(mem, -1, sizeof mem);
		cout << editDist(0, 0) << el;
		/*cout.flush();*/
		op = idxShift = 0;
		traceED(0, 0);
	} return 0;
}
