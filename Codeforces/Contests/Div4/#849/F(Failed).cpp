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

void sumOfDigits(int& num)
{
    int nnum = 0;
    while(num)
    {
        nnum+= num % 10;
        num/=10;
    }
    num = nnum;
}

void solve()
{
    int arrN, q;
    cin >> arrN >> q;

    vector<int> vec(arrN);
    for(int i = 0; i < arrN; i++)
        cin >> vec[i];
    int query,l,r,idx;
    for(int i = 0; i < q; i++)
    {
        cin >> query;
        if(query==1)
        {
            cin >> l >> r;
            l--;
            for(l; l < r; l++) {
                if(vec[l] < 10) continue;
                sumOfDigits(vec[l]);
            }
        }
        else
        {
            cin >> idx;
            cout << vec[idx-1] << el;
        }
    }
}

int main()
{
    adhamet
    
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}