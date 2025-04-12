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

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	while (cin >> n && n) {
		vector<pair<long long, long long>> p(n);
		for (int i = 0; i < n; i++)
			cin >> p[i].first >> p[i].second;

		int ans = 0;
		for (int i = 0; i < n; i++) {
			vector<pair<long long, long long>> v(n - 1);
			for (int j = 0, k = 0; j < n; j++) {
				if (j == i)
					continue;

				v[k] = p[j] - p[i];
				if (v[k].second < 0)
					v[k].first *= -1LL, v[k].second *= -1LL;
				k++;
			}
			sort(v.begin(), v.end(), cmp<long long>);
			vector<int> cnt(n - 1);
			for (int j = 0, k = 0; j < n - 1; j = k)
				while (k < n - 1 && cross(v[j], v[k]) == 0LL)
					cnt[j]++, k++;

			for (int j = 0, k = 1; j < n - 1; j++) {
				if (!k)
					break;

				while (dot(v[j], v[k]) > 0) {
					k = (k + 1) % (n - 1);
					if (k == 0)
						break;
				}
				while (k && dot(v[j], v[k]) == 0) {
					ans += cnt[j] * cnt[k];
					k = (k + 1) % (n - 1);
					if (k == 0)
						break;
				}
			}
		}

		cout << ans << '\n';
	}
}
