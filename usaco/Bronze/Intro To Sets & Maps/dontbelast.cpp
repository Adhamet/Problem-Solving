#include <bits/stdc++.h>
using namespace std;

#define el '\n'

void setIO(string name = "") {
     if (name.size()) {
         freopen((name+".in").c_str(), "r", stdin);
         freopen((name+".out").c_str(), "w", stdout);
     }
}

vector<string> allCows = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);     cout.tie(0);
    
    setIO("notlast");

    int n;  cin >> n;
    map<string, int> valuez;
    map<int,set<string>> mp;
    
    for(int i = 0; i < n; i++) {
        int val;
        string input;
        cin >> input >> val;
        valuez[input] += val;
    }

    for(auto cow: allCows) {
        if(!valuez.count(cow)) valuez[cow] = 0;
    }

    for(auto val: valuez) {
        mp[val.second].insert(val.first);
    }

    auto ansIt = mp.begin();
    ansIt++;
    
    if (ansIt == mp.end()) {
        cout << "Tie" << el;
    } else {
        set<string> ans = ansIt->second;
        if (ans.size() > 1) cout << "Tie" << el;
        else cout << *ans.begin() << el;
    }

    return 0;
}
