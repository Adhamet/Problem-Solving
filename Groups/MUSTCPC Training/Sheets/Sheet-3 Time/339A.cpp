// Helpful Maths
#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define el '\n'

int main()
{
    adhamet

    string s;
    cin >> s;
    priority_queue<int, vector<int>, greater<>> pq;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] != '+') pq.push(s[i] - 48);
    }

    while(!pq.empty())
    {
        cout << pq.top();
        pq.pop();
        if(pq.size() != 0) cout << "+";
    }

    return 0;
}