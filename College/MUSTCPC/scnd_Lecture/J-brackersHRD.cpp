#include <iostream>
#include <stack>
#include <string>
 
using namespace std;
 
int main() {
    stack<int> stk;
    string str;
 
    cin >> str;
 
    for (int i = 0; i < str.length(); i++)
    {
        if (stk.empty()) {
            stk.push(str[i]);
            continue;
        }
 
        if (str[i] == ')' && stk.top() == '(') stk.pop();
        else if (str[i] == '}' && stk.top() == '{') stk.pop();
        else if (str[i] == ']' && stk.top() == '[') stk.pop();
        else stk.push(str[i]);
    }
 
    if (stk.empty()) cout << "yes";
    else cout << "no";
 
    return 0;
}
