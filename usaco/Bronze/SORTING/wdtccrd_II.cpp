// Why Did The Cow Cross The Road - Part 2
#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
 cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

void setIO(string name = "") {
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);    
    }
}

int main()
{
    setIO("cowqueue");
    adhamet;

    int n;    cin >> n;
    vector<pair<int,int>> cows(n);
    for(int i = 0; i < n; i++) cin >> cows[i].first >> cows[i].second;

    sort(cows.begin(), cows.end());
    
    int currTime = 0;
    for(const auto& c: cows) {
        // if last cow is still asking, add to it after it finishes
        if(currTime > c.first) currTime += c.second;
        // otherwise just take the current cow as it is latest time
        else currTime = c.first + c.second;
    }
    cout << currTime << el;
    
    return 0;
}
