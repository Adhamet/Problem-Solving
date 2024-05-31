#include <bits/stdc++.h>
using namespace std;

int main() {       
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string revs; cin >> revs;
	set<char> unq(revs.begin(), revs.end());
	vector<char> distRevs(unq.begin(), unq.end());
        
	string ans = "";
        for(char c : revs) {
            int pos = find(distRevs.begin(), distRevs.end(), c) - distRevs.begin();
	    int symPos = distRevs.size() - pos - 1;
            ans += distRevs[symPos];
        }

        cout << ans << '\n'; 
    }

    return 0;
}

