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
bool cmp1(pair<pair<T, T>, int> &a, pair<pair<T, T>, int> &b) {
	// a = a-c, b = b-c;
	return atan2(a.first.second, a.first.first) < atan2(b.first.second, b.first.first);
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
bool cmp2(pair<pair<T, T>, int> &a, pair<pair<T, T>, int> &b) {
	if (quadrant(a.first) != quadrant(b.first))
		return quadrant(a.first) < quadrant(b.first);
	if (cross(a.first, b.first) == 0)
		return abs2(a.first) < abs2(b.first);
	return cross(a.first, b.first) > 0;
}

template <typename T>
vector<pair<T, T>> ConvexHull(vector<pair<T, T>> &pnts) {
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

bool check(long long x, long long y) {
	return y < 0 || (y == 0 && x < 0);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<pair<long long, long long>, int>> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].first.first >> p[i].first.second >> p[i].second;
		if (check(p[i].first.first, p[i].first.second))
			p[i].first.first *= -1, p[i].first.second *= -1;
	}
	// sort(p.begin(), p.end(), cmp1<long long>);
	// sort(p.begin(), p.end(), cmp2<long long>);
	sort(p.begin(), p.end(), [&](auto &a, auto &b) { return cross(a.first, b.first) > 0; });

	vector<int> a;
	for (int i = 0, j = 0; i < n; i = j) {
		int tot = 0;
		while (j < n && cross(p[i].first, p[j].first) == 0)
			tot += p[j++].second;
		a.push_back(tot);
	}

	int ans = 0, tot = 0;
	for (int i : a) {
		tot += i;
		ans = max(ans, tot);
		tot = max(0, tot);
	}
	int sum = 0, mn = 0;
	tot = 0;
	for (int i : a) {
		sum += i;
		tot += i;
		mn = min(mn, tot);
		tot = min(tot, 0);
	}
	ans = max(ans, sum - mn);

	cout << ans << '\n';
}
