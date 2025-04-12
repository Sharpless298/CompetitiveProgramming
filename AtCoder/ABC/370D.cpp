#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w, q;
	cin >> h >> w >> q;
	vector<set<int>> g1(h), g2(w);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			g1[i].insert(j);
			g2[j].insert(i);
		}
	}

	while (q--) {
		int r, c;
		cin >> r >> c;
		r--, c--;

		auto erase = [&](int a, int b) {
			g1[a].erase(b);
			g2[b].erase(a);
		};

		if (g1[r].count(c)) {
			erase(r, c);
			continue;
		}

		{
			auto it = g1[r].lower_bound(c);
			if (it != begin(g1[r]))
				erase(r, *prev(it));
		}
		{
			auto it = g1[r].lower_bound(c);
			if (it != end(g1[r]))
				erase(r, *it);
		}
		{
			auto it = g2[c].lower_bound(r);
			if (it != begin(g2[c]))
				erase(*prev(it), c);
		}
		{
			auto it = g2[c].lower_bound(r);
			if (it != end(g2[c]))
				erase(*it, c);
		}
	}

	int ans = 0;
	for (auto s : g1)
		ans += (int)s.size();
	cout << ans << '\n';
}
