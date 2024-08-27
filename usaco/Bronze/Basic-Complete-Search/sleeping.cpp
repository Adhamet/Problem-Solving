#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;

    int t;	cin >> t;
    while(t--) {
    	int n;	cin >> n;

    	vector<int> elsie_log(n);
    	int total_hours = 0;
    	for(int &h: elsie_log) {
    		cin >> h;
    		total_hours += h;
    	}

    	for(int hrs = 0; hrs <= total_hours; hrs++) {
    		if(hrs != 0 && total_hours % hrs != 0) {
    			continue;
    		}

    		int curr_sum = 0;
    		bool valid = true;
    		for(const int& h: elsie_log) {
    			curr_sum += h;
    			if(curr_sum > hrs) {
    				valid = false;
    				break;
    			}
    			else if(curr_sum == hrs) {
    				curr_sum = 0;
    			}
    		}

    		if (valid) {
    			if (hrs == 0) {
    				cout << 0 << el;
    			}
    			else {
    				cout << n - total_hours/hrs << el;
    			}
    			break;
    		}
    	}

    }
	
    return 0;
}