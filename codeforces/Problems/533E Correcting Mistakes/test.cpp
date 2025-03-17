#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<string.h>
#define ll long long
using namespace std;
const int N=1e3+5;
const ll MOD= 100000000  ,MAX=1e18;
const double ep=1e-6, pi=3.14159265359;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
ll n,m=1e12,k;
long long inv(long long a, long long b=MOD){
 return 1<a ? b - inv(b%a,a)*b/a : 1;
}
void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void fn()
{
    string s1, s2;

    cin >> n >> s1 >> s2;

    int i, k, j;
    int ans = 0;

    for(i = 0; s1[i] == s2[i]; i++);
    for(j = n - 1; s1[j] == s2[j]; j--);
    for(k = i; k < j && s1[k] == s2[k+1]; k++);
    if(k == j)ans++;
    for(k = i; k < j && s1[k+1] == s2[k]; k++);
    if(k == j)ans++;

    cout << ans << '\n';
    return;
}

int main()
{
    fastio();
    int t=1;
   //cin>>t;
   while(t--){
      fn();
    }
    return 0;
}

//When you play the game of thrones, you win, or you die. There is no middle ground.

