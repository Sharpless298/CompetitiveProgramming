#include <bits/stdc++.h>
using namespace std;

pair<int, int> operator+(pair<int, int> &a, pair<int, int> &b) {
	return {a.first + b.first, a.second + b.second};
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, m;
		string s;
		cin >> n >> m >> s;
		vector<vector<long long>> G(n, vector<long long>(m));
		vector<long long> r(n), c(m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> G[i][j];
				r[i] += G[i][j];
				c[j] += G[i][j];
			}
		}

		vector<pair<int, int>> mp(256);
		mp['D'] = {1, 0}, mp['R'] = {0, 1};

		pair<int, int> cur = {0, 0};
		for (int i = 0; i < (int)s.size(); i++) {
			if (s[i] == 'D') {
				G[cur.first][cur.second] = -r[cur.first];
				c[cur.second] += -r[cur.first];
			} else {
				G[cur.first][cur.second] = -c[cur.second];
				r[cur.first] += -c[cur.second];
			}
			cur = cur + mp[s[i]];
		}

		G[n - 1][m - 1] = -r[n - 1];

		for (auto i : G) {
			for (auto j : i)
				cout << j << ' ';
			cout << '\n';
		}
	}
}
