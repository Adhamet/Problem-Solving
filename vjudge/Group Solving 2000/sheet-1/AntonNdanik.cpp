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

const ll N = 1e15;

void solve()
{
    int size, a=0;
    string str;
    cin >> size >> str;

    for(int i = 0; i < size; i++) {
        if(str[i] == 'A') a+=1;
        else a-=1;
    }

    if(a==0) cout << "Friendship";
    else if (a>0) cout << "Anton";
    else cout << "Danik";
}

int main()
{
    adhamet
    
    solve();
    return 0;
}