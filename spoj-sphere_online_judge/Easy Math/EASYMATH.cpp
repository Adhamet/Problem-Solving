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

    int T;
    cin >> T;
    while(T--) {
        ll n,m,a,d,even=0,odd=0;
        cin >> n >> m >> a >> d;

        ll rng = m - n + 1;
        ll arr[] = {a,a+d,(a+2*d),(a+3*d),(a+4*d)};
        
        // Shifting left : Multpying by 2
        // Shifting right : Dividing by 2
        // shifting is way faster than looping

        for(int i = 0; i < (1<<5); i++) {
            ll LCM=1, num_of_bits=0; // LCM=1 because its a neutral number
            for(int j = 0; j < 5; j++) if ((i >> j) & 1) 
                    num_of_bits++, LCM = lcm(LCM, arr[j]);
            int temp = rng - ( (m - (n-1) ) / LCM );
            if ( num_of_bits % 2 == 0 ) even += temp;
            else odd += temp;
        }
        cout << odd - even << el;
    }
    return 0;
}
