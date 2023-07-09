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

    int n, count=0;
    cin >> n;

    int arr[n];
    bool k;
    for (int i = 0; i < n; i++) cin >> arr[i]; // 1 0 1 0 0 1 0
    for (int i = 0; i < n; i++)
    {
        if (arr[i] && !k)
            k = 1;
        if (arr[i] == 1 || ( arr[i] == 0 && arr[i - 1] == 1 && arr[i + 1] == 1 ))
            count++;
    }

    cout << count << el;
    return 0;
}
