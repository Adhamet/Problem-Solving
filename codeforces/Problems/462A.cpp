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
    
    int n, k;
    cin >> n;
    
    char arr[n+2][n+2];
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++)
            cin >> arr[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            k = 0;
            if (arr[i][j+1]=='o') k++;
            if (arr[i][j-1]=='o') k++;
            if (arr[i+1][j]=='o') k++;
            if (arr[i-1][j]=='o') k++;
            if (k % 2 == 0 || k == 0) continue;
			else {
				cout << "NO";
				return 0;
			}
        }
    
    cout << "YES";
    return 0;
}
