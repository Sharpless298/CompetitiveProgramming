#include <bits/stdc++.h>
using namespace std;

const long long INF = 0x3fffffffffffffff;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector<vector<long long>> d(n, vector<long long>(n));
	for (auto &i : d)
		for (auto &j : i)
			cin >> j;

	vector<vector<bool>> vis(2, vector<bool>(n, false));
	vector<vector<long long>> dist(2, vector<long long>(n, INF));
	dist[0][0] = 0;
	for (int i = 0; i < 2 * n; i++) {
		int t, v;
		long long mn = INF;
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < n; k++)
				if (dist[j][k] < mn && !vis[j][k])
					mn = dist[j][k], t = j, v = k;
		vis[t][v] = true;
		if (t == 0) {
			for (int j = 0; j < n; j++)
				dist[0][j] = min(dist[0][j], dist[0][v] + d[j][v] * a);
			dist[1][v] = min(dist[1][v], dist[0][v]);
		} else {
			for (int j = 0; j < n; j++)
				dist[1][j] = min(dist[1][j], dist[1][v] + d[j][v] * b + c);
		}
	}

	cout << dist[1][n - 1] << '\n';
}
