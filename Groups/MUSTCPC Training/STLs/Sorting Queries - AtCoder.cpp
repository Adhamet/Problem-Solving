#include <bits/stdc++.h>
 
using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define F first
#define S second
#define el '\n'

void solve()
{
    int queries,op,x;
    cin >> queries;
    deque<int> dq;
    priority_queue<int, vector<int>, greater<>> pq;

    while(queries--) {
        cin >> op;
        if(op == 1) 
        {
            cin >> x;
            dq.push_back(x);
        }
        else if(op == 2) 
        {
            if(pq.empty()) {
                cout << dq.front() << el;
                dq.pop_front();
            }
            else {
                cout << pq.top() << el;
                pq.pop();
            }
        }
        else 
        {
            while(!dq.empty()) {
                pq.push(dq.front());
                dq.pop_front();
             }
        }
    }
}

int main()
{
    adhamet
 
    solve();
 
    return 0;
}