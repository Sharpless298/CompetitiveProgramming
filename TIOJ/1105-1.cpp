// O(n^2)
#include <iostream>
#include <vector>
using namespace std;

pair<int, int> operator-(pair<int, int> a, pair<int, int> b) {
	return {a.first - b.first, a.second - b.second};
}

int abs2(pair<int, int> a) {
	return a.first * a.first + a.second * a.second;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	while (cin >> n && n) {
		vector<pair<int, int>> p(n);
		for (int i = 0; i < n; i++)
			cin >> p[i].first >> p[i].second;

		int mx = 0;
		pair<int, int> ans = {0x3f3f3f3f, 0x3f3f3f3f};
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int dis = abs2(p[i] - p[j]);

				if (dis == mx)
					ans = min(ans, {i, j});
				if (dis > mx)
					mx = dis, ans = {i, j};
			}
		}

		cout << ans.first << ' ' << ans.second << '\n';
	}
}
