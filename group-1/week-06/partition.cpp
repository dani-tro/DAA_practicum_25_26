#include <bits/stdc++.h>
using namespace std;

struct Point {
	long double x, y;
	Point () : x(0), y(0) {}
	Point (long double xx, long double yy) : x(xx), y(yy) {}
};

Point operator * (long double p, Point A) {
	return Point(A.x * p, A.y * p);
}
Point operator + (Point A, Point B) {
	return Point (A.x + B.x, A.y + B.y);
}

Point A, B, C, P;
long double S;

long double area(Point a, Point b, Point c) {
	return fabs((b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y)) / 2.0;
}

bool check(long double p) {
	Point Q = p * C + (1 - p) * B;
	return area(P, Q, B) * 2.0 < S;
}	

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> C.y >> B.x >> B.y >> P.x >> P.y;
	
	S = area(A, B, C);
	if (P.x == 0) swap(B, C);
	else if (P.x * B.y != P.y * B.x) swap(A, C);
	
	long double part;
	if (A.x != B.x) {
		part = (P.x - A.x) / (B.x - A.x);
	} else {
		part = (P.y - A.y) / (B.y - A.y);
	}
	
	if (part > 0.5) swap(A, B);
	
	long double l = 0, r = 1, mid;
	for (int i = 0; i < 128; i++) {
		mid = (l + r) / 2.0;
		if (check(mid)) l = mid;
		else r = mid;
	}
	
	Point Q = l * C + (1 - l) * B;
	cout << fixed << setprecision(9) << Q.x << ' ' << Q.y << endl;
}
