#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;

    int n;  cin >> n;
    vector<pair<int,char>> cows(n);
    for(int i = 0; i < n; i++)
        cin >> cows[i].second >> cows[i].first;
    
    sort(cows.begin(),cows.end());

    // Calculate cows lying on the left of every point.
    vector<int> to_the_left(n);
    for(int i = 1; i < n; i++) {
        to_the_left[i] += to_the_left[i-1];

        if(cows[i-1].second == 'L')
            to_the_left[i]++;
    }

    // Same to the right.
    vector<int> to_the_right(n);
    for(int i = n-2; i >= 0; i--) {
        to_the_right[i] += to_the_right[i+1];

        if(cows[i+1].second == 'G')
            to_the_right[i]++;
    }

    int min_liars = n;
    for(int i = 0; i < n; i++)
        min_liars = min(min_liars, to_the_left[i]+to_the_right[i]);
    cout << min_liars;
	
    return 0;
}