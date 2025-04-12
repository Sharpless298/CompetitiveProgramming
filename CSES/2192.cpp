#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// const double EPS = 1e-8;

template <typename T>
pair<T, T> operator+(pair<T, T> a, pair<T, T> b) {
	return make_pair(a.first + b.first, a.second + b.second);
}
template <typename T>
pair<T, T> operator-(pair<T, T> a, pair<T, T> b) {
	return make_pair(a.first - b.first, a.second - b.second);
}
template <typename T>
pair<T, T> operator*(pair<T, T> a, const T b) {
	return make_pair(a.first * b, a.second * b);
}
template <typename T>
pair<T, T> operator*(const T b, pair<T, T> a) {
	return make_pair(a.first * b, a.second * b);
}
template <typename T>
pair<T, T> operator/(pair<T, T> a, const T b) {
	return make_pair(a.first / b, a.second / b);
}
template <typename T>
T dot(pair<T, T> a, pair<T, T> b) {
	return a.first * b.first + a.second * b.second;
}
template <typename T>
T cross(pair<T, T> a, pair<T, T> b) {
	return a.first * b.second - a.second * b.first;
}
template <typename T>
T abs2(pair<T, T> a) {
	return dot(a, a);
}
template <typename T>
T abs(pair<T, T> a) {
	return sqrt(dot(a, a));
}

template <typename T>
int ori(pair<T, T> &a, pair<T, T> &b, pair<T, T> &p) {
	T res = cross(a - p, b - p);
	// if(fabs(res) < EPS) return 0;
	if (res == 0)
		return 0;
	return res > 0 ? 1 : -1;
}

template <typename T>
bool collinear(pair<T, T> &a, pair<T, T> &b, pair<T, T> &p) {
	// return fabs(cross(a-p, b-p)) < EPS;
	return cross(a - p, b - p) == 0;
}

template <typename T>
bool onSegment(pair<T, T> &a, pair<T, T> &b, pair<T, T> &p) {
	return collinear(a, b, p) && dot(a - p, b - p) <= 0;
}

template <typename T>
bool intersect(pair<T, T> &a, pair<T, T> &b, pair<T, T> &c, pair<T, T> &d) {
	if (onSegment(a, b, c) || onSegment(a, b, d))
		return true;
	if (onSegment(c, d, a) || onSegment(c, d, b))
		return true;
	return ori(b, c, a) * ori(b, d, a) < 0 && ori(d, a, c) * ori(d, b, c) < 0;
}

template <typename T>
pair<T, T> intersection(pair<T, T> &a, pair<T, T> &b, pair<T, T> &c, pair<T, T> &d) {
	assert(intersect(a, b, c, d));
	return a + (b - a) * cross(a - c, d - c) / cross(d - c, b - a);
}

template <typename T>
int quadrant(pair<T, T> &a) {
	if (a.first > 0 && a.second >= 0)
		return 1;
	if (a.first <= 0 && a.second > 0)
		return 2;
	if (a.first < 0 && a.second <= 0)
		return 3;
	if (a.first >= 0 && a.second < 0)
		return 4;
	return -1;
}

template <typename T>
bool cmp(pair<T, T> &a, pair<T, T> &b) {
	if (quadrant(a) != quadrant(b))
		return quadrant(a) < quadrant(b);
	if (cross(a, b) == 0)
		return abs2(a) < abs2(b);
	return cross(a, b) > 0;
}

template <typename T>
vector<pair<T, T>> getConvexHull(vector<pair<T, T>> &pnts) {
	sort(pnts.begin(), pnts.end());
	// pnts.resize(unique(pnts.begin(), pnts.end()-pnts.begin()));
	// if(pnts < 3) return pnts;

	vector<pair<T, T>> hull;
	for (int i = 0; i < 2; i++) {
		int t = (int)hull.size();
		for (pair<T, T> pnt : pnts) {
			while (hull.size() - t >= 2 && cross(hull.back() - hull[hull.size() - 2], pnt - hull[hull.size() - 2]) <= 0)
				hull.pop_back();
			hull.push_back(pnt);
		}
		hull.pop_back();
		reverse(pnts.begin(), pnts.end());
	}

	return hull;
}

int n;

template <typename T>
void point_in_polygon(vector<pair<T, T>> &polygon, pair<T, T> x) {
	for (int i = 0; i < n; i++) {
		if (onSegment(polygon[i], polygon[(i + 1) % n], x)) {
			cout << "BOUNDARY\n";
			return;
		}
	}

	int cnt = 0;
	pair<T, T> y = x + pair<T, T>{1LL, (long long)2e9 + 5};
	for (int i = 0; i < n; i++)
		if (intersect(polygon[i], polygon[(i + 1) % n], x, y))
			cnt++;

	if (cnt % 2 == 1)
		cout << "INSIDE\n";
	else
		cout << "OUTSIDE\n";
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int m;
	cin >> n >> m;
	vector<pair<long long, long long>> polygon(n);
	for (int i = 0; i < n; i++)
		cin >> polygon[i].first >> polygon[i].second;

	while (m--) {
		pair<long long, long long> p;
		cin >> p.first >> p.second;
		point_in_polygon(polygon, p);
	}
}
