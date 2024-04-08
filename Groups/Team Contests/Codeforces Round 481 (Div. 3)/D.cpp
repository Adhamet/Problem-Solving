#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'

int main()
{
    adhamet;

    int n; cin >> n;
    vector<int> arr(n);
    vector<int> diff(n-1);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(i > 0)
            diff[i-1] = abs(arr[i] - arr[i-1]);
    }

    int totalChanges = 0;
    for(int i = 0; i < n-2; i++) {
        int diff1 = diff[i];
        int diff2 = diff[i+1];

        totalChanges += abs(diff1 - diff2) - 1;
    }

    cout << totalChanges << el;

    return 0;
}
