#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pLL pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
inline int toInt(char a) {
    return a-'0';
}
int evaluate(const string& num, const int& base) {
    return toInt(num[0]) * base * base +
           toInt(num[1]) * base +
           toInt(num[2]);
}
int main()
{
    adhamet;
    
    const int minBase = 10, maxBase = 15000;
    int t;  cin >> t;
    while(t--) {
        string x,y;
        cin >> x >> y;
        int baseX=minBase,baseY=minBase;
        while(baseX<maxBase && baseY<maxBase) {
            int numX=evaluate(x,baseX), numY=evaluate(y,baseY);
            if(numX < numY) baseX++;
            else if(numX > numY) baseY++;
            else {
                cout << baseX << " " << baseY << el;
                break;
            }
        }
    }

    return 0;
}
