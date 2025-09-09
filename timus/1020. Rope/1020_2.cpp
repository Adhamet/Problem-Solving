#include <bits/stdc++.h>
#define i64 int64_t
#define PI acos(-1)

struct Pt {
	double x, y;
};
struct Vec: Pt{};

int32_t main() {
	auto induceVec = [](Pt a, Pt b) -> Vec {
		Vec res;
		res.x = b.x - a.x, res.y = b.y - a.y;
		return res;
	};

	auto getAngle = [](Vec a, Vec b) -> double {
		double dotRes = a.x*b.x + a.y*b.y;
		double normA = std::sqrt(a.x*a.x + a.y*a.y);
		double normB = std:: sqrt(b.x*b.x + b.y*b.y);
		double cosTheta = dotRes / (normA * normB);
		if (cosTheta > 1.0) cosTheta = 1.0;
		if (cosTheta < -1.0) cosTheta = -1.0;
		return std::acos(cosTheta);
	};
	
	auto dist = [](Pt a, Pt b) -> double { 
		double dx = a.x - b.x, dy = a.y - b.y;
		return sqrt(dx*dx + dy*dy);
	};

	int n;
	double r;
	scanf("%d%lf", &n, &r);
	if (n == 1) return printf("%lf", 2*PI*r), 0;

	double tangentsLengths = 0;
	std::vector<Pt> center(n);
	scanf("%lf%lf", &center[0].x, &center[0].y);
	Pt last = center[0];
	for (int i = 1; i < n; ++i) {
		scanf("%lf%lf", &center[i].x, &center[i].y);
		tangentsLengths += dist(last, center[i]);
		last = center[i];
	}
	tangentsLengths += dist(last, center[0]);

	double arcsLengths = 0;
	for (int i = 0; i < n; ++i) {
		Pt ptA = center[i];
		Pt ptB = center[(i+1)%n];
		Pt ptC = center[(i-1+n)%n];
		Vec vecA = induceVec(ptA, ptB);
		Vec vecB = induceVec(ptA, ptC);

		double angle = getAngle(vecA, vecB);
		double curArcLength = r * (PI - angle);
		arcsLengths += curArcLength;
	}

	printf("%.2lf", tangentsLengths + arcsLengths);
	return 0;
}
