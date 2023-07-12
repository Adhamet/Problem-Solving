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
    
    int j1,j2, timer=1;
    cin >> j1 >> j2;

    if (j1 == 1 && j2 == 1) {
        cout << 0;
        return 0;
    }

    while (j1 > 2 || j2 > 2)
    {
        if (j1 == 1)
        {
            j1++;
            j2 -= 2;
            timer++;
        }
        else if (j2 == 1)
        {
            j2++;
            j1 -= 2;
            timer++;
        }
        else if (j1 % 2 == 0)
        {
            j1++;
            j2 -= 2;
            timer++;
        }
        else if (j2 % 2 == 0)
        {
            j2++;
            j1 -= 2;
            timer++;
        }
        else
        {
            j1++;
            j2 -= 2;
            timer++;
        }
    }
    cout << timer;
    return 0;
}
