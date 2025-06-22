#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

struct LINE {
	int type;
	i64 val;
};

tuple<i64,i64,bool> inters(LINE a, LINE b) {
	if (a.type == b.type) return {0, 0, false};
	i64 x, y;

	// vertical & horizontal
	if ((a.type==0 && b.type==1) || (a.type==1 && b.type==0)) {
		x = (a.type==0)? a.val: b.val;
		y = (a.type==0)? b.val: a.val;
		return {x, y, true};
	}

	// vertical & main diag
	if ((a.type==0 && b.type==2) || (a.type==2 && b.type==0)) {
		// x = r, y = r + c, [(r + c) - r = c], y = y - x;
		x = (a.type==0)? a.val: b.val;
		y = (a.type==0)? b.val: a.val;
		y = y - x;
		return {x, y, true};
	}

	// vertical & anti diag
	if ((a.type==0 && b.type==3) || (a.type==3 && b.type==0)) {
		// y = r - (r - c);
		x = (a.type==0)? a.val: b.val;
		y = (a.type==0)? b.val: a.val;
		y = x - y;
		return {x, y, true};
	}

	// horizontal & main diag
	if ((a.type==1 && b.type==2) || (a.type==2 && b.type==1)) {
		x = (a.type==1)? a.val: b.val;
		y = (a.type==1)? b.val: a.val;
		y = y - x;
		return {x,y,true};
	}

	// horizontal & anti diag
	if ((a.type==1 && b.type==3) || (a.type==3 && b.type==1)) {
		x = (a.type==1)? a.val: b.val;
		y = (a.type==1)? b.val: a.val;
		y = y + x;
		return {x,y,true};
	}


	// main diag & anti diag
	if ((a.type==2 && b.type==3) || (a.type==3 && b.type==2)) {
		// r + c, r - c, [(r + c) + (r - c)] = 2r, r/=2;
		i64 xx = (a.type==2)? a.val: b.val;
		i64 yy = (a.type==2)? b.val: a.val;
		if ((xx+yy)&1) return {0, 0, false};
		x = (xx+yy)>>1;
		y = xx - x;
		return {x, y, true};
	}

	return {0, 0, false};
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, i = 0; cin >> n;
		vector<array<i64,2>> qs(n);
		for (auto& [r,c]: qs) cin >> r >> c;

		if (n == 1) {
			cout << "YES" << el << qs[0][0] << ' ' << qs[0][1] << el;
			continue;
		}

		auto getLines = [&](int i){
			auto [r,c] = qs[i];
			return vector<LINE>{
				{0, r}, {1, c},
				{2, r + c}, {3, r - c}
			};
		};

		vector<pair<int,int>> pairs = {{0,1}};
		if (n > 2) {
			pairs.emplace_back(0,2);
			pairs.emplace_back(1,2);
		}

		set<array<i64,2>> cand;
		for (auto [i,j] : pairs) {
			auto L1 = getLines(i);
			auto L2 = getLines(j);
			for (auto &a: L1) for (auto &b: L2) {
				auto [x,y,ok] = inters(a,b);
				if (ok) cand.insert({x,y});
			}
		}
		bool found = false;
		i64 ansX=0, ansY=0;
		for (auto& pt: cand) {
			i64 cx = pt[0], cy = pt[1];
			bool ok = true;
			for (auto& [qx,qy]: qs) {
				if (qx==cx || qy==cy || abs(qx-cx) == abs(qy-cy))
					continue;
				ok = false;
				break;
			}

			if (ok) {
				found = true;
				ansX=cx,ansY=cy;
				break;
			}
		}

		if (!found) cout << "NO" << el;
		else cout << "YES" << el << ansX << ' ' << ansY << el;
	} return 0;
}
