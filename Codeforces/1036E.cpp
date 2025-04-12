#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <set>
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
bool check(pair<T, T> &a, pair<T, T> &b, pair<T, T> &c, pair<T, T> &d) {
	return (__gcd(b.first - a.first, b.second - a.second) * cross(a - c, d - c)) % cross(d - c, b - a) == 0;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<long long, long long>> a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += abs(__gcd(a[i].first - b[i].first, a[i].second - b[i].second)) + 1;

		set<pair<long long, long long>> s;
		for (int j = 0; j < i; j++) {
			if (intersect(a[i], b[i], a[j], b[j]) && check(a[i], b[i], a[j], b[j]))
				s.insert(intersection(a[i], b[i], a[j], b[j]));
		}
		ans -= (int)s.size();
	}

	cout << ans << '\n';
}
