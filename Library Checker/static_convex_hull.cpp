#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;

template<typename T>
pair<T, T> operator+(pair<T, T> a, pair<T, T> b) { return make_pair(a.first+b.first, a.second+b.second); }
template<typename T>
pair<T, T> operator-(pair<T, T> a, pair<T, T> b) { return make_pair(a.first-b.first, a.second-b.second); }
template<typename T>
pair<T, T> operator*(pair<T, T> a, const T b) { return make_pair(a.first*b, a.second*b); }
template<typename T>
pair<T, T> operator*(const T b, pair<T, T> a) { return make_pair(a.first*b, a.second*b); }
template<typename T>
pair<T, T> operator/(pair<T, T> a, const T b) { return make_pair(a.first/b, a.second/b); }
template<typename T>
T dot(pair<T, T> a, pair<T, T> b) { return a.first*b.first + a.second*b.second; }
template<typename T>
T cross(pair<T, T> a, pair<T, T> b) { return a.first*b.second - a.second*b.first; }
template<typename T>
T abs2(pair<T, T> a) { return dot(a, a); }
template<typename T>
T abs(pair<T, T> a) { return sqrt(dot(a, a)); }

template<typename T>
int ori(pair<T, T> &a, pair<T, T> &b, pair<T, T> &p) {
	T res = cross(a-p, b-p);
	if(res == 0) return 0;
	return res>0 ? 1 : -1;
}

template<typename T>
bool intersect(pair<T, T> &a, pair<T, T> &b, pair<T, T> &c, pair<T, T> &d) {
	if(onSegment(a, b, c) || onSegment(a, b, d)) return true;
	if(onSegment(c, d, a) || onSegment(c, d, b)) return true;
	return ori(b, c, a)*ori(b, d, a)<0 && ori(d, a, c)*ori(d, b, c)<0;
}

template<typename T>
vector<pair<T, T>> getConvexHull(vector<pair<T, T>> &pnts) {
	sort(pnts.begin(), pnts.end());
	pnts.resize(unique(pnts.begin(), pnts.end())-pnts.begin());
	if(pnts.size() < 3) return pnts;

	vector<pair<T, T>> hull;
	for(int i=0; i<2; i++) {
		int t = (int)hull.size();
		for(pair<T, T> pnt : pnts) {
			while(hull.size()-t>=2 && cross(hull.back()-hull[hull.size()-2], pnt-hull[hull.size()-2]) <= 0)
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

	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;

		if(n == 0) {
			cout << 0 << '\n';
			continue;
		}

		vector<pair<long long, long long>> v(n);
		for(int i=0; i<n; i++) 
			cin >> v[i].first >> v[i].second;

		v = getConvexHull(v);
		cout << v.size() << '\n';
		for(auto &i:v) cout << i.first << ' ' << i.second << '\n';
	}
}
