#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int k;
struct Query {
	int l, r, id;
	bool operator<(Query &a) {
		return (l / k == a.l / k ? r < a.r : (l / k) < (a.l / k));
	}
};

int cntcnt;
vector<int> cnt;

void add(int x) {
	if (!cnt[x])
		cntcnt++;
	cnt[x]++;
}

void remove(int x) {
	cnt[x]--;
	if (!cnt[x])
		cntcnt--;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<int> v = a;
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (int i = 0; i < n; i++)
		a[i] = (int)(lower_bound(v.begin(), v.end(), a[i]) - v.begin());
	cnt.resize(v.size());

	int m;
	cin >> m;
	k = n / (int)sqrt(m);
	vector<Query> qry(m);
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		qry[i] = {l - 1, r, i};
	}
	sort(qry.begin(), qry.end());

	int l = 0, r = 0;
	vector<int> ans(m);
	for (Query q : qry) {
		while (l > q.l)
			add(a[--l]);
		while (r < q.r)
			add(a[r++]);
		while (l < q.l)
			remove(a[l++]);
		while (r > q.r)
			remove(a[--r]);
		ans[q.id] = cntcnt;
	}

	for (int i = 0; i < m; i++)
		cout << ans[i] << '\n';
}
