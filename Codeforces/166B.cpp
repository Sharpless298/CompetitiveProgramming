#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

#define Point pair<pair<long long, long long>, int>

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

vector<Point> ConvexHull(vector<Point> &pnts) {
	sort(pnts.begin(), pnts.end(), [&](Point &a, Point &b) {
		if (a.first.first == b.first.first)
			return a.first.second < b.first.second;
		return a.first.first < b.first.first;
	});

	vector<Point> hull;
	for (int i = 0; i < 2; i++) {
		int t = (int)hull.size();
		for (Point pnt : pnts) {
			while (hull.size() - t >= 2 &&
				   cross(hull.back().first - hull[hull.size() - 2].first, pnt.first - hull[hull.size() - 2].first) < 0)
				hull.pop_back();
			hull.push_back(pnt);
		}
		hull.pop_back();
		reverse(pnts.begin(), pnts.end());
	}

	return hull;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<Point> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;
		v.push_back({{x, y}, 1});
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		long long x, y;
		cin >> x >> y;
		v.push_back({{x, y}, 0});
	}

	v = ConvexHull(v);

	bool f = true;
	for (Point &p : v)
		f &= p.second;

	cout << (f ? "YES\n" : "NO\n");
}
