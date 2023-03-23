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
 
void solve(int n)
{
    queue<int> q;

    // assuming n = 6, queue = { 1 2 3 4 5 6 }
    for(int i = 1; i <= n; i++)
        q.push(i);
    
    cout << "Discarded cards: ";
    while(q.size() > 2)
    {
        cout << q.front() << ", ";
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front() << el;
    q.pop();
    cout << "Remaining card: " << q.front() << el;
}
 
int main()
{
    adhamet
 
    int T;
    while(cin >> T) {
        if(T == 0) break;
        else if(T == 1) {
            cout << "Discarded cards:\n";
            cout << "Remaining card: 1\n";
        }
        else solve(T);
    }
 
    return 0;
}