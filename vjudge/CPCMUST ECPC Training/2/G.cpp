#include <bits/stdc++.h>
using namespace std;

string reverseString(string str1)
{
    string str2;
  
    for (int i = str1.length() - 1, j = 0; i >= 0, j < str1.length(); i--, j++)
    {
        str2[j] = str1[i];
    }
    return str2;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        stack<int> stk;

        string str;
        cin >> str;

        for (int i = 0; i < str.length(); i++)
        {
            if (stk.empty()) {
                stk.push(str[i]);
            } 
            else
            {
                if (str[i] == ')' && stk.top() == '(') 
                {
                    stk.pop();
                }
                else stk.push(str[i]);

                if (stk.empty())
                {
                    
                }
            }

        }
    
        cout << n;
    }
}