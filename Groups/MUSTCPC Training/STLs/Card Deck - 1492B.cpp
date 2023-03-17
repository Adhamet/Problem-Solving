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
 
void solve(int &n, int &iR, int arr[], int res[])
{
    int maxI = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[maxI] < arr[i]) maxI = i;
    }
    
    int toBeMvd = n-maxI;
    n = maxI;
    for(int i = iR; i < iR+toBeMvd; i++, maxI++)
        res[i] = arr[maxI];
    iR+=toBeMvd;
}

int main()
{
    adhamet
 
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int arr[n],result[n], iResult = 0;

        for(int i = 0; i < n; i++)
            cin >> arr[i];
        while(n)
            solve(n, iResult, arr, result);
            
        for(int i = 0; i < iResult; i++)
            cout << result[i] << " ";
        cout << el;
    }
 
    return 0;
}