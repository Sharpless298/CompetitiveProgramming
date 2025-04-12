#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct TPoint {
	T x, y;
	int id;

	TPoint() : x(0), y(0), id(-1) {}
	TPoint(T _x, T _y) : x(_x), y(_y), id(-1) {}
	TPoint(T _x, T _y, int _id) : x(_x), y(_y), id(_id) {}

	inline TPoint operator+(const TPoint &p) {
		return TPoint(x + p.x, y + p.y);
	}
	inline TPoint operator-(const TPoint &p) {
		return TPoint(x - p.x, y - p.y);
	}
	inline TPoint operator*(const T &k) {
		return TPoint(x * k, y * k);
	}
	inline TPoint operator/(const T &k) {
		return TPoint(x / k, y / k);
	}
	friend T dot(const TPoint &p, const TPoint &q) {
		return p.x * q.x + p.y * q.y;
	}
	friend T cross(const TPoint &p, const TPoint &q) {
		return p.x * q.y - p.y * q.x;
	}
	inline bool operator<(const TPoint &p) {
		return (y < p.y || (y == p.y && x < p.x));
	}
	inline bool operator==(const TPoint &p) {
		return x == p.x && y == p.y;
	}
};
using Point = TPoint<long long>;

vector<Point> convex_hull(vector<Point> &pnts) {
	sort(pnts.begin(), pnts.end());
	pnts.resize(unique(pnts.begin(), pnts.end()) - pnts.begin());
	if (pnts.size() < 3)
		return pnts;

	vector<Point> hull;
	for (Point pnt : pnts) {
		while (hull.size() >= 2 && cross(hull.back() - hull[hull.size() - 2], pnt - hull[hull.size() - 2]) <= 0)
			hull.pop_back();
		hull.push_back(pnt);
	}
	hull.pop_back();

	reverse(pnts.begin(), pnts.end());
	int t = (int)hull.size();
	for (Point pnt : pnts) {
		while (hull.size() - t >= 2 && cross(hull.back() - hull[hull.size() - 2], pnt - hull[hull.size() - 2]) <= 0)
			hull.pop_back();
		hull.push_back(pnt);
	}
	hull.pop_back();

	return hull;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<Point> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i].x >> v[i].y;

		v = convex_hull(v);

		cout << v.size() << '\n';
		for (int i = 0; i < (int)v.size(); i++)
			cout << v[i].x << ' ' << v[i].y << '\n';
	}
}
