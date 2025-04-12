#include <iostream>
#include <stack>
using namespace std;

char G[2005][2005];
int n, m;
int d[2005][2005];
stack<pair<int, int>> stk;

bool ok(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, r, c, depth, dis, ans, ansr, ansc;

	cin >> T;
	while (T--) {
		ans = -1;

		cin.ignore();
		cin >> n >> m;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				d[i][j] = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> G[i][j];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (d[i][j] > 0)
					continue;

				r = i, c = j, depth = 0;

				do {
					d[r][c] = --depth;
					stk.push({r, c});
					if (G[r][c] == 'U')
						r--;
					else if (G[r][c] == 'D')
						r++;
					else if (G[r][c] == 'R')
						c++;
					else
						c--;
				} while (ok(r, c) && d[r][c] == 0);

				dis = 1;
				if (ok(r, c)) {
					if (d[r][c] < 0) {
						int cycle = d[r][c] - depth + 1;
						for (int k = 0; k < cycle; k++) {
							pair<int, int> p = stk.top();
							stk.pop();
							d[p.first][p.second] = cycle;
						}
					}
					dis = d[r][c] + 1;
				}

				while (!stk.empty()) {
					pair<int, int> p = stk.top();
					stk.pop();
					d[p.first][p.second] = dis++;
				}

				if (d[i][j] > ans)
					ansr = i, ansc = j, ans = d[i][j];
			}
		}

		cout << ansr + 1 << ' ' << ansc + 1 << ' ' << ans << '\n';
	}
}
