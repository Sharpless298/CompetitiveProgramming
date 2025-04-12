#include <bits/stdc++.h>
using namespace std;

struct Query {
	int l, r, id;
};

vector<int> cnt(1000001);

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, q;
		cin >> n >> q;
		vector<int> a(n);
		for (int &i : a)
			cin >> i, cnt[i] = 0;
		vector<Query> qry(q);
		for (int i = 0; i < q; i++)
			cin >> qry[i].l >> qry[i].r, qry[i].id = i;

		const int K = (int)sqrt(n);
		auto cmp = [&](Query &aa, Query &bb) {
			return (aa.l / K) ^ (bb.l / K) ? aa.l < bb.l : ((aa.l / K) & 1 ? aa.r < bb.r : aa.r > bb.r);
		};
		sort(qry.begin(), qry.end(), cmp);

		int l = 0, r = -1, odd = 0;
		vector<bool> ans(q);
		for (auto [L, R, id] : qry) {
			L--, R--;
			while (l > L) {
				cnt[a[--l]]++;
				if (cnt[a[l]] & 1)
					odd++;
				else
					odd--;
			}
			while (r < R) {
				cnt[a[++r]]++;
				if (cnt[a[r]] & 1)
					odd++;
				else
					odd--;
			}
			while (l < L) {
				cnt[a[l]]--;
				if (cnt[a[l++]] & 1)
					odd++;
				else
					odd--;
			}
			while (r > R) {
				cnt[a[r]]--;
				if (cnt[a[r--]] & 1)
					odd++;
				else
					odd--;
			}

			ans[id] = (odd == 0);
		}
		for (bool c : ans)
			cout << (c ? "YES\n" : "NO\n");
	}
}
