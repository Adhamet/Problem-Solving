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

    int n;	cin >> n;
    vector<pair<int,int>> cowsNorth, cowsEast;
    pair<int,int> arr[n];
    for(int i = 0; i < n; i++) {
    	char dir;	cin >> dir;
    	int x,y;	cin >> x >> y;
    	arr[i] = {x,y};
    	if (dir == 'N') cowsNorth.push_back({x,y});
    	else if(dir == 'E') cowsEast.push_back({x,y});
    }

    sort(cowsNorth.rbegin(), cowsNorth.rend(), [](const auto &left, const auto &right) {
    	if (left.first != right.first)
    		return left.first < right.first;
    	return left.second < right.second;
    }); 
    sort(cowsEast.rbegin(), cowsEast.rend(), [](const auto &left, const auto &right) {
    	if (left.second != right.second)
    		return left.second < right.second;
    	return left.first < right.first;
    });

    map<pair<int,int>, int> grassEaten; // ------------ O(n^2);
    for(auto cowN = cowsNorth.rbegin(); cowN != cowsNorth.rend(); cowN++) {
    	for(auto cowE = cowsEast.rbegin(); cowE != cowsEast.rend(); cowE++) {
    		if(cowE->first > cowN->first || cowE->second < cowN->second)
    			continue;
    		pair<int,int> pointOfMeet; // {8,1},{3,5}
    		pointOfMeet.first = cowN->first; //{8,}
    		pointOfMeet.second = cowE->second; //{8,5}
    		int distN, distE;
    		distN = pointOfMeet.second - cowN->second; // 4
    		distE = pointOfMeet.first - cowE->first; // 5

    		if (distN < distE) {
    			grassEaten[{cowE->first,cowE->second}] = distE;
    			auto it = find(cowsEast.begin(), cowsEast.end(), make_pair(cowE->first,cowE->second));
    			cowsEast.erase(it);
    		}
    		else if (distN > distE) {
    			grassEaten[{cowN->first,cowN->second}] = distN;
    			auto it = find(cowsNorth.begin(), cowsNorth.end(), make_pair(cowN->first,cowN->second));
    			cowsNorth.erase(it);
    			break;
    		}
    	}
    }

    for(int i = 0; i < n; i++) { 
    	if(grassEaten[{arr[i].first, arr[i].second}] == 0)
    		cout << "Infinity" << el;
    	else
    		cout << grassEaten[{arr[i].first, arr[i].second}] << el;
	}

    return 0;
}