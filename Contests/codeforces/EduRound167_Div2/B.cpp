#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
/* const int N = 2e5+5, oo=INT_MAX+7, MOD=INT_MAX+7; */

int main()
{
    adhamet;

    int t;  cin >> t;
    while(t--) {
        string subst,subsq; cin >> subsq >> subst;
        bool decide = false;
        vector<pair<int,vi>> occs(subsq.size());
        int l = 0;
        for(int i = 0; i < subsq.size(); i++) {
            for(int j = 0; j < subst.size(); j++) {
                if(subsq[i]==subst[j]) {
                    occs[l].F=i;
                    occs[l].S.push_back(j);
                    decide = true;
                }
            }
            l++;
        }
        
        int maxLen = decide? 1: 0, currLen;
        decide = false;
        for(auto occ: occs) {
            for(int i = 0; i < occ.S.size(); i++) {
                currLen = 1;
                int b = occ.F+1;
                int c = occ.S[i]+1;
                if(b>=subsq.size() || c>=subst.size()) break;
                else {
                    while(b<subsq.size()) {
                        if(subsq[b] == subst[c]) {
                            b++;
                            currLen++;
                        }
                        c++;
                        if(c == subst.size()) {
                            maxLen = max(maxLen, currLen);
                            currLen = 1;
                            b++;
                            c = occ.S[i]+1;
                        }
                    }
                }
                maxLen=max(maxLen,currLen);
                if(maxLen == subsq.size()) decide=true;
                if(decide)break;
            }
        }
        cout << subst.size()+subsq.size()-maxLen << el;
    }

    return 0;
}
