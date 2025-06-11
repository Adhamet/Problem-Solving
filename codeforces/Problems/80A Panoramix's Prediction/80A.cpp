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

bool isPrime(int n)
{
    if (n <= 1)
        return false;
  
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    bool flag=1;
    for(int i = n+1; i < m; i++) if(isPrime(i))
    {
        flag = false;
        break;
    }
    
    if(flag) 
    { 
        if(isPrime(m))
            cout << "YES";
        else cout << "NO";
    }
    else cout << "NO";
}

int main()
{
    adhamet;
    
    solve();
    return 0;
}