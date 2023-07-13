#include <bits/stdc++.h>

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

int main()
{
    adhamet
    
    int n;
    cin >> n;
    vector<int> input(n);
    for (int &x : input) cin >> x;
    vector<int> sets[3];
    // 0 = Negative, 1 = Positive, 2 = Zero

    for (int x : input) {
        if ( x == 0 ) sets[2].push_back(x);
        else if ( x > 0 ) sets[1].push_back(x);
    }

    bool test = sets[1].empty();

    for (int x : input) {
        if ( x >= 0 ) continue;

        if (test && sets[1].size() < 2) sets[1].push_back(x);
        else if ( sets[0].empty() ) sets[0].push_back(x);
        else sets[2].push_back(x);
    }

    for (int i = 0; i < 3; i++)
    {
        cout << sets[i].size();
        for (int x : sets[i])
            cout << " " << x;
        cout << el;
    }

    return 0;
}
