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

int main()
{
    adhamet;
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
	int q, op, x;	cin >> q;
	deque<int> dq;
	priority_queue<int, vector<int>, greater<int>> pq;

	while(q--) {
		cin >> op;
		if (op == 1) {
			cin >> x;
			dq.push_back(x);
		}
		else if (op == 2) {
			if (pq.empty()) {
				cout << dq.front() << el;
				dq.pop_front();
			}
			else {
				cout << pq.top() << el;
				pq.pop();
			}
		}
		else {
			while(!dq.empty()) {
				pq.push(dq.front());
				dq.pop_front();
			}
		}
	}
	
    return 0;
}