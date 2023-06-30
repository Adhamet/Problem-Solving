// Songs Compression
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

    int n,b,temp,least=0;
    ll sum=0;
    cin >> n >> b;
    int arr[n];
    priority_queue<int> pq;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cin >> temp;
        pq.push(arr[i] - temp);
        sum += arr[i];
    }

    while (sum > b && !pq.empty()) {
        sum -= pq.top();
        pq.pop();
        least++;
    }

    if (sum > b) cout << "-1";
    else cout << least;

    return 0;
}
