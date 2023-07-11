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
    
    int k,d;
    cin >> k >> d;

    int arr[k];

    if (k > 1 && d > 0)
    {
        arr[0]=1;
        arr[k-1]=d-1;

        for(int i = 1; i < k-1; i++)
            arr[i] = 0;
        for(int i = 0; i < k; i++)
            cout << arr[i];
    }
    else if (k > 1 && d == 0)
        cout << "No solution";
    else
        cout << d;

    return 0;
}
