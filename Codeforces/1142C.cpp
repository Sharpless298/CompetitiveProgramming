#include <algorithm>
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
	reverse(pnts.begin(), pnts.end());

	vector<pair<T, T>> hull;
	for (pair<T, T> pnt : pnts) {
		while (hull.size() >= 2 && cross(hull.back() - hull[hull.size() - 2], pnt - hull[hull.size() - 2]) <= 0)
			hull.pop_back();
		hull.push_back(pnt);
	}
	if (hull.back().first == hull[hull.size() - 2].first)
		hull.pop_back();

	return hull;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<long long, long long>> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
		p[i].second -= p[i].first * p[i].first;
	}

	p = convex_hull(p);
	cout << p.size() - 1 << '\n';
}
