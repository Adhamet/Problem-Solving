#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1)

struct pt {
	double x, y;
};

int32_t main() {
	int n;
	double r;
	scanf("%d%lf", &n, &r);

	auto dist = [](pt a, pt b) {
		double dx = a.x - b.x, dy = a.y - b.y;
		return sqrt(dx*dx + dy*dy);
	};

	double polygonPerimeter = 0;
	pt first;	
	scanf("%lf%lf", &first.x, &first.y);
	pt last = first;
	for (int i = 0; i < n - 1; ++i) {
		pt cur;
		scanf("%lf%lf", &cur.x, &cur.y);
		polygonPerimeter += dist(last, cur);
		last = cur;
	}
	polygonPerimeter += dist(last, first);

	/*fprintf(stderr, "TEST: %.2f and %.2f\n", polygonPerimeter, 2 * PI * double(r));*/
	printf("%.2f\n", polygonPerimeter + 2 * PI * r);
	return 0;
}

