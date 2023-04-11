// Replacing Elements
#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define el '\n'

int main()
{
    adhamet

    int t;
    cin >> t;
    while(t--)
    {
        int n,d;
        cin >> n >> d;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr+n);

        (d >= (arr[0] + arr[1]) || d >= arr[n-1]) ? cout << "YES\n": cout << "NO\n";
    }

    return 0;
}