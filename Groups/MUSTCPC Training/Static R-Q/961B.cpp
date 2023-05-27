    // Lecture sleep
    #include <bits/stdc++.h>
    #include <algorithm>
    using namespace std;
    #define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #define ll long long
    #define lld long long double
    #define intPair pair<int,int>
    #define llPair pair<ll,ll>
    #define ldPair pair<lld,lld>
    #define F first
    #define S second
    #define el '\n'

    void solve()
    {
        int n,m;
        cin >> n >> m;
        vector<ll> theo(n+1),behv(n+1),h(n+1);
        for(int i = 1; i <= n; i++) cin >> theo[i];
        for(int i = 1; i <= n; i++) cin >> behv[i];

        for(int i = 1; i <= n; i++)
        {
            h[i] = h[i-1];
            
            if (behv[i]) h[i] += theo[i];
            theo[i] += theo[i-1];
        }

        ll res = 0;
        for(int i=1; i < n-m+1; i++)
        {
            res = max(res, h[i-1] - theo[i-1] + theo[i+m-1] + h[n] - h[i+m-1]);
        }

        cout << res << el;
    }

    int main()
    {
        adhamet;

        solve();

        return 0;
    }




    /* FAILED ATTEMP
    void solve()
    {
        int n,k;
        ll max = 0;
        cin >> n >> k;

        ll theorems[n], behavior[n], holder[n];
        for(int minute = 0; minute < n; minute++)
            cin >> theorems[minute];
        for(int minute = 0; minute < n; minute++) {
            cin >> behavior[minute];
            if(behavior[minute] == 1)
                holder[minute] = minute > 0? holder[minute-1] + theorems[minute]: theorems[minute];
            else
                holder[minute] = minute > 0? holder[minute-1]: 0;
            max += behavior[minute] * theorems[minute];
        }
        
        ll currentMax=0;
        for(int minute = 0; minute < n; minute++) if(behavior[minute] == 0)
        {
            currentMax = holder[minute];
            for(int i = 0, j = minute; i < k && j < n; i++, j++)
            {
                currentMax += theorems[j];
            }
            if(max < currentMax) max = currentMax;
        }

        cout << max;
    }
    */