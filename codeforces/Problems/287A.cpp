#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define el '\n'

bool isPossible(int a, int b, char grid[4][4])
{
    int count = 0;
    for(int i = a; i < a+2; i++)
        for(int j = b; j < b+2; j++)
            if (grid[i][j] == '#')
                count++;
    if (count == 2)
        return false;
    return true;
}

int main() 
{
/* #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
#endif */
    adhamet
    
	char grid[4][4];

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            cin >> grid[i][j];
    
    bool possible = false;

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if (isPossible(i,j,grid)) {
                possible = true;
                break;
            }
    
    possible? cout << "YES" << el: cout << "NO" << el;

	return 0;
}
