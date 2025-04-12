#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int &i : a)
			cin >> i;

		vector<int> d(n);
		vector<vector<int>> G(n);
		for (int i = 1; i < n; i++) {
			int u;
			cin >> u;
			u--;
			G[u].push_back(i);
			d[i] = d[u] + 1;
		}

		vector<long long> b(n);
		for (int i = 0; i < n; i++) {
			if (G[i].empty())
				b[i] = 0x3f3f3f3f;
			else {
				b[i] = -a[i];
				for (int v : G[i])
					b[i] += a[v];
			}
		}

		long long ans = 0;
		for (int i = n - 1; i >= 0; i--) {
			queue<int> q;

			q.push(i);
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (int v : G[u]) {
					long long delta = min(-b[i], b[v]);

					if (delta > 0) {
						b[i] += delta;
						b[v] -= delta;
						ans += delta * (d[v] - d[i]);
					}
					q.push(v);
				}
			}
		}

		cout << ans << '\n';
	}
}
