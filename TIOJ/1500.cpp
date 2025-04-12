#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

long double dis(long double a, long double b, long double c, long double d) {
	return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	while (cin >> n) {
		vector<pair<long double, long double>> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i].first >> v[i].second;

		sort(v.begin(), v.end(),
			 [&](pair<long double, long double> &a, pair<long double, long double> &b) { return a.second < b.second; });

		long double ans = 1e19;
		set<pair<double, double>> s;
		for (int i = 0, j = 0; i < n; i++) {
			while (v[j].second + ans <= v[i].second)
				s.erase(v[j++]);
			auto iter = s.lower_bound({v[i].first - ans, -1e20});
			while (iter != s.end() && iter->first <= v[i].first + ans) {
				ans = min(ans, dis(iter->first, iter->second, v[i].first, v[i].second));
				iter++;
			}
			s.insert(v[i]);
		}

		cout << fixed << setprecision(6) << ans << '\n';
	}
}
