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

		bool f = true;
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				if (G[i][j] != '1')
					continue;

				int a = i - 1, p = 1;
				while (a >= 0) {
					p &= (G[a][j] - '0');
					a--;
				}
				int b = j - 1, q = 1;
				while (b >= 0) {
					q &= (G[i][b] - '0');
					b--;
				}
				f &= (p || q);
			}
		}

		cout << (f ? "YES\n" : "NO\n");
	}
}
