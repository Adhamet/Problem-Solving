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

vector<int> check(int n, vi arr, int x) {
    multiset<int> ms;   for(auto ele: arr) ms.insert(ele);
    vi res;
    for(int i = 0; i < n; i++) {
        auto it1 = ms.end(); it1--;
        int y = x - *it1;   ms.erase(it1);
        auto it2 = ms.find(y);
        if(it2 == ms.end()) return {};
        res.push_back(x - y);   res.push_back(y);
        x = max(x-y, y);
        ms.erase(it2);
    }
    return res;
}

int main()
{
    adhamet;

    int t;  cin >> t;
    while(t--) {
        bool acc=false;
        int n;  cin >> n;
        vi arr(2*n);    for(int i = 0; i < 2*n; i++) cin >> arr[i];
        sort(arr.begin(),arr.end());
        for(int i = 0; i < 2*n-1; i++) {
            int x = arr[i] + arr[2*n-1];
            vi res = check(n, arr, x);
            if(res.size()) {
                cout << "YES\n" << x << el;
                for(int j = 0; j < n; j++) cout << res[j*2] << " " << res[2*j+1] << el;
                acc = true;
                break;
            }
        }
        if(!acc) cout << "NO\n";
    }

    return 0;
}
