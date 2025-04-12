#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct Query {
	int l, r, block, id;
	bool operator<(Query &a) {
		return (block ^ a.block) ? block < a.block : ((block & 1) ? r < a.r : r > a.r);
	}
};

const int MOD = 1e9 + 7;

int sum;
vector<int> v, cnt;

int f(int x) {
	return (int)(1LL * cnt[x] * cnt[x] % MOD * v[x] % MOD);
}

void add(int x) {
	sum = (sum - f(x) + MOD) % MOD;
	cnt[x]++;
	sum = (sum + f(x)) % MOD;
}

void remove(int x) {
	sum = (sum - f(x) + MOD) % MOD;
	cnt[x]--;
	sum = (sum + f(x)) % MOD;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;
	int k = n / (int)sqrt(q);
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	v = a;
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (int i = 0; i < n; i++)
		a[i] = (int)(lower_bound(v.begin(), v.end(), a[i]) - v.begin());

	vector<Query> qry(q);
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		qry[i] = {l, r, l / k, i};
	}
	sort(qry.begin(), qry.end());

	int l = 0, r = 0;
	vector<int> ans(q);
	cnt.resize(v.size());
	for (Query i : qry) {
		while (l > i.l)
			add(a[--l]);
		while (r < i.r)
			add(a[r++]);
		while (l < i.l)
			remove(a[l++]);
		while (r > i.r)
			remove(a[--r]);

		ans[i.id] = sum;
	}

	for (int i = 0; i < q; i++)
		cout << ans[i] << '\n';
}
