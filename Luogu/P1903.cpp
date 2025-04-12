#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct Query {
	int l, r, t, bl, br, id;
	bool operator<(Query &a) {
		return (bl ^ a.bl ? bl < a.bl : (br ^ a.br ? r < a.r : (br & 1 ? t < a.t : t > a.t)));
	}
};

struct Modify {
	int k, x;
};

int tmp;
vector<int> a, cnt(1000001);

void add(int x) {
	if (!cnt[x])
		tmp++;
	cnt[x]++;
}

void remove(int x) {
	cnt[x]--;
	if (!cnt[x])
		tmp--;
}

void update(Query p, Modify &q) {
	if (p.l <= q.k && q.k < p.r) {
		remove(a[q.k]);
		add(q.x);
	}
	swap(a[q.k], q.x);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	int k = (int)pow(n, 2.0 / 3);
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int qid = 0, tid = 0;
	vector<Query> qry;
	vector<Modify> mod;
	mod.push_back({0, 0});
	for (int i = 0; i < m; i++) {
		char c;
		cin >> c;

		if (c == 'Q') {
			int l, r;
			cin >> l >> r;
			qry.push_back({l - 1, r, tid, (l - 1) / k, r / k, qid});
			qid++;
		} else {
			int x, y;
			cin >> x >> y;
			tid++;
			mod.push_back({x - 1, y});
		}
	}
	sort(qry.begin(), qry.end());

	int l = 0, r = 0, t = 0;
	vector<int> ans(qry.size());
	for (Query q : qry) {
		while (l < q.l)
			remove(a[l++]);
		while (l > q.l)
			add(a[--l]);
		while (r < q.r)
			add(a[r++]);
		while (r > q.r)
			remove(a[--r]);
		while (t < q.t)
			update(q, mod[++t]);
		while (t > q.t)
			update(q, mod[t--]);
		ans[q.id] = tmp;
	}

	for (int i = 0; i < (int)qry.size(); i++)
		cout << ans[i] << '\n';
}
