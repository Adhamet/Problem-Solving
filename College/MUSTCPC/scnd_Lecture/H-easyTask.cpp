#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
 
int main() {
	int op, ele, n, m;
	deque<int> dq;
	cin >> n >> m;
 
	for (int i = 0; i < n; i++)
	{
		cin >> ele;
		dq.push_back(ele);
	}
 
	for (int i = 0; i < m; i++) 
	{
		cin >> op;
		if (op == 1) reverse(dq.begin(), dq.end());
		else if (op == 2)
		{
			cin >> op >> ele;
			if (op == 1) {
				dq.push_front(ele);
			}
			else dq.push_back(ele);
		}
	}
 
	cout << dq.size() << endl;
	while (!dq.empty())
	{
		cout << dq.front() << " ";
		dq.pop_front();
	}
}