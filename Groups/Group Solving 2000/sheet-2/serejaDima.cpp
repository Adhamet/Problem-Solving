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

deque<int> dq;

int calculate(int &player)
{
    if(dq.front() > dq.back()) {
        player += dq.front();
        dq.pop_front();
    }
    else {
        player += dq.back();
        dq.pop_back();
    }
    return player;
}

void solve()
{
    int size,x,Sereja=0,Dima=0;
    cin >> size;
    for(int i = 0; i < size; i++) {
        cin >> x;
        dq.push_back(x);
    }
    bool SerejaTurn = 1;
    while(!dq.empty()) {
        if(SerejaTurn) {
            calculate(Sereja);
            SerejaTurn = 0;
        }
        else {
            calculate(Dima);
            SerejaTurn = 1;
        }
    }

    cout << Sereja << " " << Dima << el;
}

int main()
{
    adhamet

    solve();
    return 0;
}