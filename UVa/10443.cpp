#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	bool f[256][256] = {};
	f['R']['S'] = true;
	f['S']['P'] = true;
	f['P']['R'] = true;

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int r, c, n;
		cin >> r >> c >> n;
		vector<vector<char>> G(r, vector<char>(c));
		for (auto &i : G)
			for (auto &j : i)
				cin >> j;

		while (n--) {
			vector<vector<char>> nG = G;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					for (pair<int, int> p : vector<pair<int, int>>{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}) {
						int ni = i + p.first;
						int nj = j + p.second;

						if (0 <= ni && ni < r && 0 <= nj && nj < c) {
							if (f[(int)G[ni][nj]][(int)G[i][j]]) {
								nG[i][j] = G[ni][nj];
							}
						}
					}
				}
			}
			G = nG;
		}

		if (t)
			cout << '\n';
		for (auto i : G) {
			for (auto j : i)
				cout << j;
			cout << '\n';
		}
	}
}
