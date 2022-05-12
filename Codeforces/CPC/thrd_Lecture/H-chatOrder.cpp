#include <iostream>
#include <string> 
#include <map>
 
using namespace std;
 
int main() 
{
    int n;
    cin >> n;
    string* s = new string[n];
 
    map<string, int> mp;
 
    for (int i = 0; i < n; i++)
        cin >> s[i];
 
    for (int i = n - 1; i >= 0; i--)
    {
        if (mp[s[i]] != 1) {
            cout << s[i] << endl;
            mp[s[i]] = 1;
        }
    }
}