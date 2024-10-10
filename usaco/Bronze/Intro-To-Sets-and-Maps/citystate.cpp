#include <bits/stdc++.h>
using namespace std;

#define el '\n'

void setIO(string name = "") {
     if (name.size()) {
         freopen((name+".in").c_str(), "r", stdin);
         freopen((name+".out").c_str(), "w", stdout);
     }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);     cout.tie(0);
    
    setIO("citystate");
    int n;  cin >> n;
    vector<pair<string,string>> pairs;
    for(int i = 0; i < n; i++) {
        string city, state;
        cin >> city >> state;
        city = city.substr(0,2);
        pairs.push_back({city,state});
    }

    map<string,int> seen;
    long long total = 0;
    for(const auto &[c,s]: pairs) {
        if(c!=s) total+=seen[s+c];
        seen[c+s]++;
    }
    cout << total << el;

    return 0;
}

