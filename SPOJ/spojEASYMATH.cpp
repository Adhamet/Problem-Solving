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

void solve()
{
    int n,m,a,d;
    cin >> n >> m >> a >> d;

    int dvs[5] = {a,a+d,a+(2*d),a+(3*d),a+(4*d)};
    
    int cntr=0;
    for(int iA = 0; iA < 2; ++iA)
        for(int iApD = 0; iApD < 2; ++iApD)
            for(int iAp2D = 0; iAp2D < 2; ++iAp2D)
                for(int iAp3D = 0; iAp3D < 2; ++iAp3D)
                    for(int iAp4D = 0; iAp4D < 2; ++iAp4D) {
                        int d = 1, elCnt=0;

                        if(iA) d *= dvs[0], ++elCnt;
                        if(iApD) d *= dvs[1], ++elCnt;
                        if(iAp2D) d *= dvs[2], ++elCnt;
                        if(iAp3D) d *= dvs[3], ++elCnt;
                        if(iAp4D) d *= dvs[4], ++elCnt;

                        if(elCnt == 0) continue;

                        int sign = elCnt % 2 == 1 ? 1 : -1;

                        cntr += sign * m / d;
                    }
    cout << cntr ;
}

int main()
{
    //adhamet

    int T;
    cin >> T;
    while(T--) {
       solve();
    }
    return 0;
}