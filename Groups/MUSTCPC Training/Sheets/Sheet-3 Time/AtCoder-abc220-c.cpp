// Long Sequence
#include <bits/stdc++.h>
using namespace std;

#define adhamettt ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define el '\n'

int main()
{
    adhamettt

    ll x,sum=0;
    cin >> x;

    int arr[x];

    for(int i = 0; i < x; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    ll y, count, ans;
    cin >> y;

    count = (y/sum);
    ans = count*sum;
    count *= x;
    for(int i = 0; i < x; i++)
    {
        if(ans <= y) { ans += arr[i]; count++; }
        else break;
    }

    cout << count;
    return 0;
}