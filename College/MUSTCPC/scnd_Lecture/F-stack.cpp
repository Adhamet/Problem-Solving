#include <iostream>
#include <string>
#include <stack>
using namespace std;
 
int main()
{
	int q, ele;
	string str;
	stack<int> stk;
 
	cin >> q;
 
	while (q--) {
		cin >> str;
		if (str == "push") {
			cin >> ele;
			stk.push(ele);
		}
		else if (str == "top") cout << stk.top() << endl;
		else if (str == "pop") stk.pop();
	}
}
