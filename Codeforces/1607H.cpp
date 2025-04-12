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
		vector<int> a(n), b(n), m(n);
		map<int, vector<int>> mp;
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i] >> m[i];
			mp[a[i] + b[i] - m[i]].push_back(i);
		}

		int ans = 0;
		vector<int> x(n), y(n);
		for (auto it : mp) {
			vector<int> id = it.second;
			int nn = (int)id.size();
			vector<int> L(nn), R(nn);
			for (int i = 0; i < nn; i++) {
				L[i] = max(0, a[id[i]] - m[id[i]]);
				R[i] = a[id[i]] + min(0, b[id[i]] - m[id[i]]);
			}
			vector<pair<int, int>> p(nn);
			for (int i = 0; i < nn; i++)
				p[i] = make_pair(R[i], L[i]);
			sort(p.begin(), p.end());

			int mx = -1;
			vector<int> v;
			for (int i = 0; i < nn; i++) {
				if (mx < p[i].second) {
					mx = p[i].first;
					v.push_back(mx);
				}
			}
			ans += (int)v.size();
			for (int i = 0; i < nn; i++) {
				int c = (int)(upper_bound(v.begin(), v.end(), R[i]) - v.begin() - 1);
				x[id[i]] = a[id[i]] - v[c];
				y[id[i]] = m[id[i]] - x[id[i]];
			}
		}

		cout << ans << '\n';
		for (int i = 0; i < n; i++)
			cout << x[i] << ' ' << y[i] << '\n';
	}
}
