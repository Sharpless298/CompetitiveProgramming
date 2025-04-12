#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;

int n, ans;
pair<int, int> p[10005];

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> n && n) {
		ans = 0;

		for (int i = 0; i < n; i++)
			cin >> p[i].first >> p[i].second;

		sort(p, p + n, cmp);
		for (int i = 0, sum = 0; i < n; i++) {
			sum += p[i].first;
			ans = max(ans, sum + p[i].second);
		}

		cout << ans << '\n';
	}
}
