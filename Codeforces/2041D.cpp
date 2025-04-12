#include <bits/stdc++.h>
using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
int dis[200000][4][4];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> G(n, vector<char>(m));
	int S, T;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> G[i][j];
			if (G[i][j] == 'S')
				S = i * m + j;
			if (G[i][j] == 'T')
				T = i * m + j;
		}
	}

	memset(dis, -1, sizeof(dis));
	queue<tuple<int, int, int>> q;
	dis[S][0][0] = 0;
	q.push({S, 0, 0});
	while (!q.empty()) {
		auto [u, d, t] = q.front();
		q.pop();

		int r = u / m, c = u % m;
		for (int i = 0; i < 4; i++) {
			int nr = r + dy[i];
			int nc = c + dx[i];
			int nt = t * (d == i) + 1;

			if (G[nr][nc] == '#' || nt > 3 || dis[nr * m + nc][i][nt] != -1)
				continue;
			dis[nr * m + nc][i][nt] = dis[u][d][t] + 1;
			q.push({nr * m + nc, i, nt});
		}
	}

	int ans = 0x3f3f3f3f;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (dis[T][i][j] != -1)
				ans = min(ans, dis[T][i][j]);
	cout << (ans == 0x3f3f3f3f ? -1 : ans) << '\n';
}
