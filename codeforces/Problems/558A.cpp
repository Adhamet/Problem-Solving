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

void solve(vector<int> &dir, ll &sum)
{
    sum += dir.back();
    dir.pop_back();
}

int main()
{
    adhamet

    int n;
    cin >> n;

    vector<int> neg,pos;
    vector<intPair> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i].first >> vec[i].second;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++) {
        if ( vec[i].first < 0 )
            neg.push_back(vec[i].second);
        else
            pos.push_back(vec[i].second);
    }
    reverse(pos.begin(), pos.end());

    ll sum = 0;
    if (pos.size() > neg.size()) while (true) {
        solve(pos, sum);
        if (!neg.empty())
            solve(neg, sum);
        else break;
    }
    else if (pos.size() < neg.size()) while (true) {
        solve(neg, sum);
        if (!pos.empty())
            solve(pos, sum);
        else break;
    }
    else while (!neg.empty()) {
        solve(neg, sum);
        solve(pos, sum);
    }
    cout << sum << el;

    return 0;
}
