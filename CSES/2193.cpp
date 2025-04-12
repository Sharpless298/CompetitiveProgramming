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
double abs(pair<T, T> a) {
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
bool on_segment(pair<T, T> &a, pair<T, T> &b, pair<T, T> &p) {
	return collinear(a, b, p) && dot(a - p, b - p) <= 0;
}

template <typename T>
bool intersect(pair<T, T> &a, pair<T, T> &b, pair<T, T> &c, pair<T, T> &d) {
	if (on_segment(a, b, c) || on_segment(a, b, d))
		return true;
	if (on_segment(c, d, a) || on_segment(c, d, b))
		return true;
	return ori(b, c, a) * ori(b, d, a) < 0 && ori(d, a, c) * ori(d, b, c) < 0;
}

template <typename T>
pair<T, T> intersection(pair<T, T> &a, pair<T, T> &b, pair<T, T> &c, pair<T, T> &d) {
	assert(intersect(a, b, c, d));
	return a + (b - a) * cross(a - c, d - c) / cross(d - c, b - a);
}

template <typename T>
bool cmp1(pair<T, T> &a, pair<T, T> &b) {
	// a = a-c, b = b-c;
	if (atan2(a.second, a.first) - atan2(b.second, b.first) != 0)
		return atan2(a.second, a.first) < atan2(b.second, b.first);
	return abs(a) < abs(b);
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
bool cmp2(pair<T, T> &a, pair<T, T> &b) {
	if (quadrant(a) != quadrant(b))
		return quadrant(a) < quadrant(b);
	if (cross(a, b) == 0)
		return abs2(a) < abs2(b);
	return cross(a, b) > 0;
}

template <typename T>
vector<pair<T, T>> convex_hull(vector<pair<T, T>> &pnts) {
	sort(pnts.begin(), pnts.end());
	// pnts.resize(unique(pnts.begin(), pnts.end())-pnts.begin());
	// if(pnts < 3) return pnts;

	vector<pair<T, T>> hull;
	for (pair<T, T> pnt : pnts) {
		while (hull.size() >= 2 && cross(hull.back() - hull[hull.size() - 2], pnt - hull[hull.size() - 2]) <= 0)
			hull.pop_back();
		hull.push_back(pnt);
	}
	hull.pop_back();

	reverse(pnts.begin(), pnts.end());
	int t = (int)hull.size();
	for (pair<T, T> pnt : pnts) {
		while (hull.size() - t >= 2 && cross(hull.back() - hull[hull.size() - 2], pnt - hull[hull.size() - 2]) <= 0)
			hull.pop_back();
		hull.push_back(pnt);
	}
	hull.pop_back();

	return hull;
}

template <typename T>
T area(vector<pair<T, T>> &p) {
	T res = 0;
	for (int i = 0; i < (int)p.size(); i++)
		res += cross(p[i], p[(i + 1) % p.size()]);
	// return res / 2;
	return abs(res);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<long long, long long>> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second;

	long long cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += abs(__gcd(p[i].first - p[(i + 1) % n].first, p[i].second - p[(i + 1) % n].second));

	cout << (area(p) + 2 - cnt) / 2 << ' ' << cnt << '\n';
}
