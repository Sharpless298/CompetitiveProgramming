#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
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

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	while (cin >> n && n) {
		vector<pair<long long, long long>> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i].first >> v[i].second;

		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				for (int k = j + 1; k < n; k++)
					if (dot(v[j] - v[i], v[k] - v[i]) == 0 || dot(v[i] - v[j], v[k] - v[j]) == 0 ||
						dot(v[i] - v[k], v[j] - v[k]) == 0)
						cnt++;

		cout << cnt << '\n';
	}
}
