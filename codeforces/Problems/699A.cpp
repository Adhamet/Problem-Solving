#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define el '\n'
int main() 
{
/* #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
#endif */
    adhamet
    
	int n;
    cin >> n;
    char moves[n];
    priority_queue<int, vector<int>, greater<int>> answers;

    int x,y;
    for(int i = 0; i < n; i++) cin >> moves[i];
    for(int i = 0; i < n - 1; i++) {
        cin >> x;
        if (moves[i] == 'R' && moves[i+1] == 'L') {
            cin >> y;
            answers.push(y - x);
            i++;
        }
    }
    
    if (answers.empty()) cout << -1;
    else cout << (answers.top() / 2);

	return 0;
}
