#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> w(n, vector<int>(n));
		vector<vector<int>> G(n);
		for (int i = 0; i < m; i++) {
			int u, v, x;
			cin >> u >> v >> x;
			u--, v--;

			G[u].push_back(v);
			G[v].push_back(u);
			w[u][v] = w[v][u] = (w[u][v] == 0 ? x : min(w[u][v], x));
		}
		vector<int> s(n);
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}

		vector<vector<long long>> d(n, vector<long long>(n, 0x3fffffffffffffff));
		priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
		d[0][0] = 0;
		pq.push(make_tuple(d[0][0], 0, 0));
		while (!pq.empty()) {
			auto [dis, u, b] = pq.top();
			pq.pop();

			for (int v : G[u]) {
				int tmp = (s[b] < s[v] ? b : v);
				if (d[u][b] + w[u][v] * s[b] < d[v][tmp]) {
					d[v][tmp] = d[u][b] + w[u][v] * s[b];
					pq.push(make_tuple(d[v][tmp], v, tmp));
				}
			}
		}

		cout << *min_element(d[n - 1].begin(), d[n - 1].end()) << '\n';
	}
}
