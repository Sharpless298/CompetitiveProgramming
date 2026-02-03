#include <bits/stdc++.h>
using namespace std;

struct Node {
	int u, parity, dis;
	bool operator<(const Node &rhs) const {
		return dis > rhs.dis;
	}
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, m, l;
		cin >> n >> m >> l;

		vector<int> odds, evens;
		for (int i = 0; i < l; i++) {
			int x;
			cin >> x;
			if (x & 1) {
				odds.push_back(x);
			} else {
				evens.push_back(x);
			}
		}
		sort(odds.begin(), odds.end());
		sort(evens.begin(), evens.end());

		vector<vector<int>> G(n);
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}

		vector<array<int, 2>> d(n, {INT_MAX, INT_MAX});
		priority_queue<Node> pq;
		d[0][0] = 0;
		pq.push((Node){0, 0, d[0][0]});
		while (!pq.empty()) {
			auto [u, parity, dis] = pq.top();
			pq.pop();
			if (d[u][parity] != dis) {
				continue;
			}

			for (int v : G[u]) {
				if (d[u][parity] + 1 < d[v][parity ^ 1]) {
					d[v][parity ^ 1] = d[u][parity] + 1;
					pq.push((Node){v, parity ^ 1, d[v][parity ^ 1]});
				}
			}
		}

		int sum = accumulate(evens.begin(), evens.end(), 0) + accumulate(odds.begin(), odds.end(), 0);
		int mx_even = sum;
		if (odds.size() & 1) {
			mx_even -= odds[0];
		}
		int mx_odd = INT_MIN;
		if (!odds.empty()) {
			mx_odd = sum;
			if (odds.size() % 2 == 0) {
				mx_odd -= odds[0];
			}
		}
		for (int i = 0; i < n; i++) {
			cout << (d[i][0] <= mx_even || d[i][1] <= mx_odd);
		}
		cout << '\n';
	}
}
