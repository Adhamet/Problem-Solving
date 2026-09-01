//وَقُل رَّبِّ زِدْنِي عِلْمًا
//{وَأَنْ لَيْسَ لِلإِنسَانِ إِلَّا مَا سَعَى ۝ وَأَنَّ سَعْيَهُ سَوْفَ يُرَى}
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define YES {cout<<"Yes\n";return;}
#define NO {cout<<"No\n";return;}
#define MUN {cout<<"-1\n";return;}
using namespace std;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=4*1e18;
void solve() {
    int n;cin>>n;
    vector<int>nw(n),old(n);
    vector<pair<int,int>>v(n);
    for (int i=0;i<n;i++) cin>>nw[i];
    for (int i=0;i<n;i++) cin>>old[i];
    for (int i=0;i<n;i++) v[i]={old[i],nw[i]};

    sort(v.begin(),v.end(), [](auto X, auto Y) {
        return X.first < Y.first;
    });

    int cur=0,ans=0;
    for (int i=0;i<n;i++) {
        if (v[i].first - v[i].second < cur) {
            MUN;
        } else if (v[i].first - v[i].second > cur) {
            ans += (v[i].first - v[i].second) - cur;
            cur = v[i].first - v[i].second;
        }
    }

    cout<<ans<<endl;
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--)solve();
}
