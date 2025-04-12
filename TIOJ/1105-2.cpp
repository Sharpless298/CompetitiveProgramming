#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

#define Point pair<pair<int, int>, int>

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

vector<Point> convex_hull(vector<Point> &pnts) {
	sort(pnts.begin(), pnts.end(), [&](Point &a, Point &b) {
		return a.first.first ^ b.first.first ? a.first.first < b.first.first : a.first.second < b.first.second;
	});
	// pnts.resize(unique(pnts.begin(), pnts.end()-pnts.begin()));
	// if(pnts < 3) return pnts;

	vector<Point> hull;
	for (Point pnt : pnts) {
		while (hull.size() >= 2 &&
			   cross(hull.back().first - hull[hull.size() - 2].first, pnt.first - hull[hull.size() - 2].first) <= 0)
			hull.pop_back();
		hull.push_back(pnt);
	}
	hull.pop_back();

	reverse(pnts.begin(), pnts.end());
	int t = (int)hull.size();
	for (Point pnt : pnts) {
		while (hull.size() - t >= 2 &&
			   cross(hull.back().first - hull[hull.size() - 2].first, pnt.first - hull[hull.size() - 2].first) <= 0)
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
	while (cin >> n && n) {
		vector<Point> p(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i].first.first >> p[i].first.second;
			p[i].second = i;
		}
		p = convex_hull(p);

		if (n == 2) {
			cout << 0 << ' ' << 1 << '\n';
			continue;
		}

		int dis = -0x3f3f3f3f;
		pair<int, int> ans = {0x3f3f3f3f, 0x3f3f3f3f};
		auto f = [&](Point &a, Point &b) {
			int tmp = abs2(a.first - b.first);
			if (tmp == dis)
				ans = min({ans, {a.second, b.second}, {b.second, a.second}});
			if (tmp > dis) {
				ans = min(pair<int, int>{a.second, b.second}, {b.second, a.second});
				dis = tmp;
			}
		};
		n = (int)p.size();
		for (int i = 0, j = 2; i < n; i++) {
			int ni = (i + 1) % n;
			while (true) {
				int nj = (j + 1) % n;
				if (cross(p[j].first - p[i].first, p[j].first - p[ni].first) <
					cross(p[nj].first - p[i].first, p[nj].first - p[ni].first))
					j = nj;
				else
					break;
			}
			f(p[j], p[i]);
			f(p[j], p[ni]);
		}

		cout << ans.first << ' ' << ans.second << '\n';
	}
}
