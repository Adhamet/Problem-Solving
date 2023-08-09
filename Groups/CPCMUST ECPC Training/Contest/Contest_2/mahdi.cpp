#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>

 int pos(char c1)
 {
    return c1 - 'a';
 }
 char chr(int i)
 {
    return i + 'a';
 }
 string get_string(char c, int l, int mul, int add)
 {
    string s = "";
    s += c;

    for(int i = 1; i < l; i++) {
        s += chr( (pos(s[i-1]) * mul + (i*add))%26 );
    }
    return s;
 }

int main() 
{
    adhamet;

    //freopen("mahdi.in", "r", stdin);
    
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ":" << endl;
        char ch;
        int l,mul,add;
        cin >> ch >> l >> mul >> add;

        string org = get_string(ch,l,mul,add), word;
        int w;
        cin >> w;

        while(w--) 
        {
            int lastI=0;
            bool success = true;
            cin >> ch >> l >> mul >> add;
            word = get_string(ch,l,mul,add);

            for(int z = 0; z < word.size(); z++) // "ace" "abcde"
                for(int j = lastI; j < org.size(); j++)
                {
                    if (word[z] == org[j]) {
                        lastI=j;
                        break;
                    }
                    else if (j == org.size()-1) {
                        success = false;
                        break;
                    }
                }
            if (!success) cout << "REPEAT" << endl;
            else cout << "BRAVO" << endl;
        }
    }
 
	return 0;
}
