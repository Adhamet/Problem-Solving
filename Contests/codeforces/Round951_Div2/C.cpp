#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int n;
bool acc;
vector<int> k;
vector<int> sol(int i, vector<int> vec) {
    if(vec.size() == n) {
        long long f;
        for(int i = 0; i < vec.size(); i++) f+=vec[i];
        f+=i;

        bool works = true;
        for(int i = 0; i < vec.size(); i++) if(vec[i]*k[i] >= f)
            works = false;
        if(i*k[vec.size()] >= f) works = false;

        if(works) {
            acc = true;
            return vec;
        }
        return {};
    }

    for(int i = 1; i <= 1e9; i++) {
        vector<int> v(vec.begin(),vec.end());
        v.push_back(i);
        sol(i, v);
    }

    return {};
}

int main() {
	ios_base::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    
    int t;  cin >> t;
    while(t--) {
        acc = false;
        cin >> n;
        k.clear();
        k.resize(n);
        for(int i = 0; i < n; i++) cin >> k[i];

        vector<int> ans = sol(0, {});

        if(!acc) cout << -1 << el;
        else for(int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << el;
    }
    
    return 0;
}


