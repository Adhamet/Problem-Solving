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
    adhamet;
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    
    int N, K, chars=0;
    string s;
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> s;
        chars += s.size();
        if (chars <= K) {
            if (i != 0 ) { cout << ' ';}
            cout << s;
        } else {
            cout << el << s;
            chars = s.size();
        }
    }

    return 0;
}
