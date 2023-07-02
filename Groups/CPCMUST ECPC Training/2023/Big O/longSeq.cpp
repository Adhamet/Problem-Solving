// Long Sequence
#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define el '\n'

int main()
{
    adhamet

    ll x, sum = 0;
    cin >> x;

    int arr[x];

    for(int i = 0; i < x; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    ll y, count, ans;

    cin >> y;

    count = (y/sum);
    ans = count * sum; // 2
    count *= x;

    // 20
    // 6
    for(int i = 0; i < x; i++) 
    {
        // 20 <= 26 ,   20 += 3 = 23, count += 1 (count = 7)
        // 23 <= 26 ,   23 += 5 = 28, count += 1 (count = 8)
        // 28 <= 26
        if(ans <= y) { ans += arr[i]; count++; } // 28 > 26
        else break;
    }
    // {3,5,2,3,5,2,3,5}
    // 8

    cout << count;
    
    return 0;
}

// O(n);
