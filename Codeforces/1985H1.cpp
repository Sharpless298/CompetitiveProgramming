#include <cstring>
#include <iostream>
#include <numeric>
using namespace std;

int parent[1000005], sz[1000005];

void init(int n) {
	iota(parent, parent + n, 0);
	for (int i = 0; i < n; i++)
		sz[i] = 1;
}

int Find(int x) {
	return x == parent[x] ? x : parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a), b = Find(b);

	if (a == b)
		return;

	if (sz[a] > sz[b])
		swap(a, b);
	parent[a] = b;
	sz[b] += sz[a];
}

int vis[1000005];
string G[1000005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, n, m, ans;

	cin >> T;
	while (T--) {
		ans = 0;

		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> G[i];

		const int N = n * m;
		init(N);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (G[i][j] == '#') {
					if (i + 1 < n && G[i + 1][j] == '#')
						Union(i * m + j, (i + 1) * m + j);
					if (j + 1 < m && G[i][j + 1] == '#')
						Union(i * m + j, i * m + j + 1);
				}
			}
		}

		fill(vis, vis + N, -1);
		for (int i = 0; i < n; i++) {
			int tot = 0;
			for (int j = 0; j < m; j++) {
				if (G[i][j] == '.')
					tot++;
				for (int k = max(0, i - 1); k <= min(n - 1, i + 1); k++) {
					if (G[k][j] == '#') {
						int u = Find(k * m + j);

						if (vis[u] != i) {
							vis[u] = i;
							tot += sz[u];
						}
					}
				}
			}
			ans = max(ans, tot);
		}
		fill(vis, vis + N, -1);
		for (int i = 0; i < m; i++) {
			int tot = 0;
			for (int j = 0; j < n; j++) {
				if (G[j][i] == '.')
					tot++;

				for (int k = max(0, i - 1); k <= min(m - 1, i + 1); k++) {
					if (G[j][k] == '#') {
						int u = Find(j * m + k);

						if (vis[u] != i) {
							vis[u] = i;
							tot += sz[u];
						}
					}
				}
			}
			ans = max(ans, tot);
		}

		cout << ans << '\n';
	}
}
