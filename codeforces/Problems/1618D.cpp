#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
	
	priority_queue<ll> pq;
	stack<ll> stk;
	ll max = 0;
	int op,x;
	ll num;
	cin >> op;
	while(op--) {
		cin >> x;
		if ( x == 1 ) {
			cin >> num;
			pq.push(num);
			stk.push(num);
			cout << pq.top() << el;
		}
		else {
			if(stk.top() == pq.top()) pq.pop();
			stk.pop();
			cout << pq.top() << el;
		}
	}
	
    return 0;
}
