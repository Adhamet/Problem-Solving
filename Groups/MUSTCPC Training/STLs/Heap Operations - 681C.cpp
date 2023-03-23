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
    int n,x,log=0;
    cin >> n;
    priority_queue<int, vector<int>, greater<>> pq;
    vector<string> output;
    
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if(s == "insert")
        {
            cin >> x;
            pq.push(x);
            output.push_back(s + " " + to_string(x));
        }
        else if(s == "removeMin")
        {
            if(pq.empty()){
                output.push_back("insert " + to_string(0));
                pq.push(0);
            }
            pq.pop();
            output.push_back(s);
        }
        else
        {
            cin >> x;
            while(!pq.empty() && pq.top() < x)
            {
                pq.pop();
                output.push_back("removeMin");
            }
            if(pq.empty() || pq.top() != x)
            {
                pq.push(x);
                output.push_back("insert " + to_string(x));
            }
            output.push_back(s + " " + to_string(x));
        }
    }

    cout << output.size() << endl;
    for(auto op: output)
        cout << op << el;
}
 
int main()
{
    adhamet
 
    solve();
 
    return 0;
}