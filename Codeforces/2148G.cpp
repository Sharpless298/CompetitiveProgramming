#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<int>> factors(N + 1);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j * j <= i; j++) {
			if (i % j == 0) {
				factors[i].push_back(j);
				if (j * j != i) {
					factors[i].push_back(i / j);
				}
			}
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int mx = 0;
		vector<int> cnt(n + 1);
		vector<int> b;
		vector<bool> vis(n + 1);
		for (int i = 0; i < n; i++) {
			vector<int> nxt;
			for (int j : factors[a[i]]) {
				cnt[j]++;
				if (cnt[j] != i + 1) {
					mx = max(mx, cnt[j]);
				} else if (!vis[j]) {
					nxt.push_back(j);
					vis[j] = true;
				}
			}

			for (int j : b) {
				if (cnt[j] == i + 1) {
					nxt.push_back(j);
				} else {
					mx = i;
					vis[j] = false;
				}
			}
			cout << mx << " \n"[i + 1 == n];
			b = nxt;
		}
	}
}
