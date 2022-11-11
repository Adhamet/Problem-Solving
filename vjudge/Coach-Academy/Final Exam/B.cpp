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

void testCase()
{
    int n,x,temp;
    cin >> n >> x;
    cout << "0 ";
    while(--n)
    {
        cin >> temp;
        x = temp | x;
        cout << (x^temp) << " ";
    }
    cout << endl;
}

int main()
{
    adhamet
    int T;
    cin >> T;
    while(T--)
    {
        testCase();
    }

    return 0;
}