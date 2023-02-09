#include <bits/stdc++.h>
 
using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define ull unsigned ll /* longer than Long Long */
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define F first
#define S second
#define el '\n'

const ll N = 1e12+5;

int main()
{
    map<char,pair<int,pair<int,int>>> ing;
    string str;
    getline(cin, str);
    for(int i = 0; i < str.size(); i++)
        ing[(char(i))].F++;
    cin >> ing['B'].S.first >> ing['S'].S.first >> ing['C'].S.first;
    cin >> ing['B'].S.second >> ing['S'].S.second >> ing['C'].S.second;
    int rubles;
    cin >> rubles;

    int ans = 0;
    for(int i = 0; i <= N;i++)
    {
        int nB = (ing['B'].F*i) - ing['B'].S.first;
        int nS = (ing['S'].F*i) - ing['S'].S.first;
        int nC = (ing['C'].F*i) - ing['C'].S.first;

        if(nB < 0) nB=0;
        if(nS < 0) nS=0;
        if(nC < 0) nC=0;

        
    }
}