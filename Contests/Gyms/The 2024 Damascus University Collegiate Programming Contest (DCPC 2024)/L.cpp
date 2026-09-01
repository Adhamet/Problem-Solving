//وَقُل رَّبِّ زِدْنِي عِلْمًا
//{وَأَنْ لَيْسَ لِلإِنسَانِ إِلَّا مَا سَعَى ۝ وَأَنَّ سَعْيَهُ سَوْفَ يُرَى}
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ll long long
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "0\n"; return;}
using namespace std;
void solve() {
    int n;cin>>n;
    vector<int>v(n+1);
    int mx=0,ind=0;
    for (int i=1;i<=n;i++) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    //||v[n/2-1]==v[n/2-2]
    if (n%2==0) {
        if (v[n/2]==v[n/2+1])YES;
    }
    if (v[(n+1)/2]==v[(n+1)/2-1]) {
        YES;
    }
    NO;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin >> t;
    while (t--) {
        solve();
    }
}
