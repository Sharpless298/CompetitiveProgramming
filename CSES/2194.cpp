#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

const long long INF = 9e18;

long long dis(long long a, long long b, long long c, long long d) {
	return (a - c) * (a - c) + (b - d) * (b - d);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<long long, long long>> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end(), [&](pair<long long, long long> &a, pair<long long, long long> &b) {
		return a.second ^ b.second ? a.second < b.second : a.first < b.first;
	});
	long long ans = INF;
	set<pair<long long, long long>> s;
	for (int i = 0, j = 0; i < n; i++) {
		while (v[j].second + (long long)sqrt(ans) < v[i].second)
			s.erase(v[j++]);
		auto iter = s.lower_bound({v[i].first - (long long)sqrt(ans), -INF});
		while (iter != s.end() && iter->first <= v[i].first + (long long)sqrt(ans)) {
			ans = min(ans, dis(iter->first, iter->second, v[i].first, v[i].second));
			iter++;
		}
		s.insert(v[i]);
	}

	cout << ans << '\n';
}
