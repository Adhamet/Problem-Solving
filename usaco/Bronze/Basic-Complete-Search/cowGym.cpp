#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);	
	}
}

int main()
{
    adhamet;
    setIO("gymnastics");

    int k,n;	cin >> k >> n;

    vector<vector<int>> rankings(k, vector<int>(n));
    for(int i = 0; i < k; i++)
    	for(int j = 0; j < n; j++)
    		cin >> rankings[i][j];

    vector<vector<int>> better(n, vector<int>(n));
    for(int i = 0; i < k; i++)
    	for(int j = 0; j < n; j++)
    		for(int l = j+1; l < n; l++)
    			better[rankings[i][j]-1][rankings[i][l]-1]++;

    int consistent_pairs = 0;
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < n; j++)
    		if (better[i][j] == k)
    			consistent_pairs++;

    cout << consistent_pairs;

    return 0;
}