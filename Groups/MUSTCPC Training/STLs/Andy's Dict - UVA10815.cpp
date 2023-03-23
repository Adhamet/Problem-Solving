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
 
    string input, curr;
    set<string> st;

    while(cin >> input)
    {
        curr = "";
        for(int i = 0; i < input.size(); i++)
        {
            char c = tolower(input[i]);
            if(islower(c))
                curr += c;
            else if (curr != "")
            {
                st.insert(curr);
                curr = "";
            }
        }
        if(curr != "")
            st.insert(curr);
    }

    for(auto itm: st)
        cout << itm << el;
 
    return 0;
}