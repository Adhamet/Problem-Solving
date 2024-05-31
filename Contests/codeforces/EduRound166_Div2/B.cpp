#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define el '\n'
#define ll long long
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n), b(n + 1);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n + 1; i++) cin >> b[i];

        long long lst = b.back();
        long long diff = 1e10, ans = 0;

        bool acc = false;
        for(int i = 0; i < n; i++) {
            ans += abs(a[i]-b[i]);

            if(lst <= max(a[i],b[i]) && lst >= min(a[i],b[i]))
                acc = true;

            diff = min(diff, min(abs(lst-a[i]), abs(lst-b[i])));
        }

        if(acc) ans++;
        else ans += diff + 1;
        cout << ans << el;
    }

    return 0;
}

