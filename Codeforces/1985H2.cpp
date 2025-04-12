#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int parent[1000005], sz[1000005];

void init(int n) {
	iota(parent, parent + n, 0);
	fill(sz, sz + n, 1);
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

int ans, n, m;
string G[1000005];

void solve() {
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

	vector<int> r(n, 0), c(m, 0), mxR(N, -1), mnR(N, n), mxC(N, -1), mnC(N, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (G[i][j] == '.')
				r[i]++, c[j]++;
			else {
				int u = Find(i * m + j);
				mxR[u] = max(mxR[u], min(n - 1, i + 1));
				mnR[u] = min(mnR[u], max(0, i - 1));
				mxC[u] = max(mxC[u], min(m - 1, j + 1));
				mnC[u] = min(mnC[u], max(0, j - 1));
			}
		}
	}

	vector<int> R(n + 1, 0), C(m + 1, 0);
	vector<vector<int>> RC(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i < N; i++) {
		if (Find(i) == i && G[i / m][i % m] == '#') {
			R[mnR[i]] += sz[i];
			R[mxR[i] + 1] -= sz[i];

			C[mnC[i]] += sz[i];
			C[mxC[i] + 1] -= sz[i];

			RC[mnR[i]][mnC[i]] += sz[i];
			RC[mxR[i] + 1][mnC[i]] -= sz[i];
			RC[mnR[i]][mxC[i] + 1] -= sz[i];
			RC[mxR[i] + 1][mxC[i] + 1] += sz[i];
		}
	}

	for (int i = 1; i < n; i++)
		R[i] += R[i - 1];
	for (int i = 1; i < m; i++)
		C[i] += C[i - 1];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0)
				continue;
			else if (i == 0)
				RC[i][j] += RC[i][j - 1];
			else if (j == 0)
				RC[i][j] += RC[i - 1][j];
			else
				RC[i][j] += RC[i - 1][j] + RC[i][j - 1] - RC[i - 1][j - 1];
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ans = max(ans, R[i] + C[j] - RC[i][j] + r[i] + c[j] - (G[i][j] == '.'));

	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;

	cin >> T;
	while (T--)
		solve();
}
