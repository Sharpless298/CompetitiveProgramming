#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int m = 0;
		vector<vector<int>> a(n);
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			m = max(m, k);
			a[i].resize(k);
			for (int j = 0; j < k; j++) {
				cin >> a[i][j];
			}
		}

		vector<priority_queue<pair<int, int>>> pq(m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < (int)a[i].size(); j++) {
				pq[j].push(make_pair(-a[i][j], i));
			}
		}

		priority_queue<pair<int, int>> cur;
		vector<int> ans(m);
		for (int i = 0; i < m; i++) {
			bool f = false;
			priority_queue<pair<int, int>> nxt;
			if (cur.empty()) {
				int v = pq[i].top().first;
				while (!pq[i].empty() && pq[i].top().first == v) {
					auto [x, y] = pq[i].top();
					if ((int)a[y].size() == i + 1) {
						f = true;
						break;
					}
					nxt.push(make_pair(-a[y][i + 1], y));
					pq[i].pop();
				}
				ans[i] = -v;
			} else {
				int v = cur.top().first;
				while (!cur.empty() && cur.top().first == v) {
					auto [x, y] = cur.top();
					if ((int)a[y].size() == i + 1) {
						f = true;
						break;
					}
					nxt.push(make_pair(-a[y][i + 1], y));
					cur.pop();
				}
				ans[i] = -v;
			}
			if (f) {
				cur = priority_queue<pair<int, int>>();
			} else {
				cur = nxt;
			}
		}
		for (int i = 0; i < m; i++) {
			cout << ans[i] << " \n"[i + 1 == m];
		}
	}
}
