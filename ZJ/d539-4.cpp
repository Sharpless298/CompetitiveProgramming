#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define lowbit(x) x & -x

struct Query {
	int l, r, id;
	bool operator<(Query &a) {
		return l > a.l;
	}
};

int n;
vector<int> BIT;

void update(int id, int x) {
	for (; id <= n; id += lowbit(id))
		BIT[id] = max(BIT[id], x);
}

int query(int id) {
	int res = 0;
	for (; id; id -= lowbit(id))
		res = max(res, BIT[id]);
	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	BIT.resize(n + 1);

	int m;
	cin >> m;
	vector<Query> qry(m);
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		if (l > r)
			swap(l, r);
		qry[i] = {l - 1, r, i};
	}
	sort(qry.begin(), qry.end());

	int pre = n;
	vector<int> ans(m);
	for (int i = 0; i < m; i++) {
		for (int j = qry[i].l; j < pre; j++)
			update(j + 1, a[j]);
		pre = qry[i].l;
		ans[qry[i].id] = query(qry[i].r);
	}

	for (int i = 0; i < m; i++)
		cout << ans[i] << '\n';
}
