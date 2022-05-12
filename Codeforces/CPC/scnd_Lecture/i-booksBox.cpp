#include <iostream>
#include <stack>
using namespace std;
 
int main()
{
	int t, act, ele;
	stack<int> stk;
 
	cin >> t;
	
	while (t--) {
		cin >> act;
		if (act == 1) {
			cin >> ele;
			stk.push(ele);
		}
		else if (act == 2 && !(stk.empty())) { stk.pop(); }
		else if (act == 3 && !(stk.empty())) cout << stk.top() << endl;
	}
}