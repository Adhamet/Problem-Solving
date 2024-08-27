#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pLL pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;

    int t;  cin >> t;
    while(t--) {
        string s;   cin >> s;
        int acount=0,bcount=0;
        if(s[0]=='A') acount++;
        else bcount++;
        vi agroups;
        for(int i = 1; i < s.size(); i++) {
            if(s[i]=='A') acount++;
            else {
                if(s[i-1]=='A') {
                    agroups.push_back(acount);
                    acount=0;
                }
                bcount++;
            }
        }
        if(acount>0) agroups.push_back(acount);
        if(bcount>=agroups.size()) cout << s.size() - bcount << el;
        else cout << s.size() - bcount - *min_element(agroups.begin(),agroups.end()) << el;
    }

    return 0;
}
