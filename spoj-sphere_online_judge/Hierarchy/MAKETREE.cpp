#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define ull unsigned long long
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define el '\n'

const int N = 1e5+5;
vector< vector<int> > adjL(N);
bool vis[N];
int parent[N];
vector<int> topological_sort;

void dfs(int node) {
    vis[node]=1;
    for(auto child: adjL[node]) if (!vis[child])
        dfs(child);
    topological_sort.push_back(node);
}

int main() 
{/* #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
#endif */
    adhamet
    
    int n,k,w,x;
    cin >> n >> k;

    for(int i = 1; i <= k; i++) 
    {
        cin >> w;
        while(w--) {
            cin >> x;
            adjL[i].push_back(x);
        }
    }

    for(int i = 1; i <= n; i++) if (!vis[i])
        dfs(i);
    
    int pos=0, student;
    for(int i = n - 1; i >= 0; i--) {
        student = topological_sort[i];
        parent[student] = pos;
        pos = student;
    }

    for(int i = 1; i <= n; i++)
        cout << parent[i] << el;

	return 0;
}
