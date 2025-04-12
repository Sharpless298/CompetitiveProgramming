#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];

		for (int i = 0; i < n; i++)
			sort(a[i].begin(), a[i].end());

		bool ok = true;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < m; j++)
				if (a[i][j] - a[i][j - 1] != n)
					ok = false;
		}

		if (!ok)
			cout << -1 << '\n';
		else {
			vector<pair<int, int>> v;
			for (int i = 0; i < n; i++)
				v.push_back({a[i][0], i});

			sort(v.begin(), v.end(), [](pair<int, int> &p, pair<int, int> q) { return p.first < q.first; });
			for (auto i : v)
				cout << i.second + 1 << ' ';
			cout << '\n';
		}
	}
}
