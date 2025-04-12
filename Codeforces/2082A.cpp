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
		vector<vector<char>> G(n, vector<char>(m));
		for (auto &i : G)
			for (auto &j : i)
				cin >> j;

		int r = 0, c = 0;
		for (int i = 0; i < n; i++) {
			int rr = 0;
			for (int j = 0; j < m; j++) {
				rr ^= (G[i][j] - '0');
			}
			r += rr;
		}
		for (int i = 0; i < m; i++) {
			int cc = 0;
			for (int j = 0; j < n; j++) {
				cc ^= (G[j][i] - '0');
			}
			c += cc;
		}

		cout << max(r, c) << '\n';
	}
}
