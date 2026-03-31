#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		string t;
		cin >> t;
		vector<string> s(n);
		array<set<pair<int, int>>, 26> pos;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			for (int j = 0; j < m; j++) {
				pos[s[i][j] - 'a'].insert(make_pair(i, j));
			}
		}

		vector<tuple<int, int, int, int>> ans;
		auto op = [&](int type, int x, int y, int z) {
			ans.push_back(make_tuple(type, x + 1, y + 1, z + 1));
		};
		for (int i = 0; i < m; i++) {
			if (t[i] == s[0][i]) {
				pos[t[i] - 'a'].erase(make_pair(0, i));
				continue;
			}
			pair<int, int> p = *pos[t[i] - 'a'].begin();
			pos[t[i] - 'a'].erase(p);
			if (p.second != i) {
				op(1, p.first, i, p.second);
				pos[s[p.first][i] - 'a'].erase(make_pair(p.first, i));
				pos[s[p.first][i] - 'a'].insert(make_pair(p.first, p.second));
				swap(s[p.first][i], s[p.first][p.second]);
			}

			if (p.first == 0) {
				continue;
			}
			op(2, p.first, 0, i);
			pos[s[0][i] - 'a'].erase(make_pair(0, i));
			pos[s[0][i] - 'a'].insert(make_pair(p.first, i));
			swap(s[0][i], s[p.first][i]);
		}

		cout << ans.size() << '\n';
		for (auto [a, b, c, d] : ans) {
			cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
		}
	}
}
