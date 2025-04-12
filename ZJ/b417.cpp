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

int ans;
vector<int> cnt(100001), cntcnt(100001);

void add(int x) {
	cntcnt[cnt[x]]--;
	cnt[x]++;
	cntcnt[cnt[x]]++;
	ans = max(ans, cnt[x]);
}

void remove(int x) {
	cntcnt[cnt[x]]--;
	cnt[x]--;
	cntcnt[cnt[x]]++;
	if (ans == cnt[x] + 1 && cntcnt[cnt[x] + 1] == 0)
		ans = cnt[x];
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	k = n / (int)sqrt(m);
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<Query> q(m);
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		q[i] = {l - 1, r, i};
	}
	sort(q.begin(), q.end());

	int l = 0, r = 0;
	vector<int> ans1(m), ans2(m);
	for (Query i : q) {
		while (l > i.l)
			add(a[--l]);
		while (r < i.r)
			add(a[r++]);
		while (l < i.l)
			remove(a[l++]);
		while (r > i.r)
			remove(a[--r]);
		ans1[i.id] = ans, ans2[i.id] = cntcnt[ans];
	}

	for (int i = 0; i < m; i++)
		cout << ans1[i] << ' ' << ans2[i] << '\n';
}
