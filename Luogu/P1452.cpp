#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

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
vector<pair<T, T>> convex_hull(vector<pair<T, T>> &pnts) {
	sort(pnts.begin(), pnts.end());
	// pnts.resize(unique(pnts.begin(), pnts.end()-pnts.begin()));
	// if(pnts < 3) return pnts;

	vector<pair<int, int>> hull;
	for (auto pnt : pnts) {
		while (hull.size() >= 2 && cross(hull.back() - hull[hull.size() - 2], pnt - hull[hull.size() - 2]) <= 0)
			hull.pop_back();
		hull.push_back(pnt);
	}
	hull.pop_back();

	reverse(pnts.begin(), pnts.end());
	int t = (int)hull.size();
	for (pair<int, int> pnt : pnts) {
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

	int n;
	cin >> n;
	vector<pair<int, int>> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second;
	p = convex_hull(p);

	int dis = -0x3f3f3f3f;
	n = (int)p.size();
	for (int i = 0, j = 2; i < n; i++) {
		int ni = (i + 1) % n;
		while (true) {
			int nj = (j + 1) % n;
			if (cross(p[j] - p[i], p[j] - p[ni]) < cross(p[nj] - p[i], p[nj] - p[ni]))
				j = nj;
			else
				break;
		}
		dis = max({dis, abs2(p[j] - p[i]), abs2(p[j] - p[ni])});
	}

	cout << dis << '\n';
}
