#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define lowbit(x) x & -x

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

	vector<int> v = a;
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (int i = 0; i < n; i++)
		a[i] = (int)(lower_bound(v.begin(), v.end(), a[i]) - v.begin());

	BIT.resize(n + 1);

	for (int i = 0; i < n; i++)
		update(a[i] + 1, query(a[i]) + 1);

	cout << query(n) << '\n';
}
