#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define F first
#define S second
#define intPair pair<int,int>
const int N = 1e5+10, oo = 1e9+7;
int dist[26][26];
vector< pair<int,intPair> > edges;
int n;
bool negCycle = false;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
            if ( i != j )
                dist[i][j] = oo;

    int moves;
    cin >> moves;
    while(moves--)
    {
        char u, v;
        int w;
        cin >> u >> v >> w;
        dist[u-'a'][v-'a'] = min( dist[(u-'a')][(v-'a')], w );
    }
    
    // Floyd Warshall technique: -----------------------------------------
    for(int k = 0; k < 26; k++)
        for(int i = 0; i < 26; i++)
            for(int j = 0; j < 26; j++)
                if ( dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    // -------------------------------------------------------------------

    if (str1.size() != str2.size())
        return cout << "-1\n", 0;   
    int sum = 0;
    for(int i = 0; i < str1.size(); i++)
    {
        int u = str1[i] - 'a', v = str2[i] - 'a';
        int converti = -1, smallestVal = oo;
        for(int j = 0; j < 26; j++)
            if ( dist[u][j] + dist[v][j] < smallestVal )
            {
                smallestVal = dist[u][j] + dist[v][j];
                converti = j;
            }   
        if ( converti == -1 )
        {
            cout << "-1\n";
            return 0;
        }
        sum += smallestVal;
        str1[i] = 'a' + converti; 
    }
    cout << sum << '\n' << str1 << '\n';
}