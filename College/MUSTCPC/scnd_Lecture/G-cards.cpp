
#include <iostream>
#include <deque>
using namespace std;
 
int main()
{
	int t;
	cin >> t;
 
	while (t--) {
		deque<int> dq;
		int temp;
		cin >> temp;
 
		for (int i = temp; i > 0; i--)
			dq.push_front(i);
 
		while (dq.size() > 1) {
			cout << dq.front() << " ";
			dq.pop_front();
			temp = dq.front();
			dq.pop_front();
			dq.push_back(temp);
		}
 
		cout << endl << dq.front() << endl;
	}
}