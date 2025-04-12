#include <bits/stdc++.h>
using namespace std;

struct BIT {
	int n;
	vector<int> bit;

	BIT(int _n) : n(_n) {
		bit.assign(n + 1, 0);
	}
	void update(int i, int x) {
		for (; i <= n; i += (i & -i))
			bit[i] += x;
	}
	int query(int i) {
		int sum = 0;
		for (; i; i -= (i & -i))
			sum += bit[i];
		return sum;
	}
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, Case = 0;
	while (cin >> n && n) {
		vector<int> a(n);
		for (int &i : a)
			cin >> i;

		vector<int> b = a;
		sort(b.begin(), b.end());
		b.resize(unique(b.begin(), b.end()) - b.begin());
		for (int i = 0; i < n; i++)
			a[i] = (int)(lower_bound(b.begin(), b.end(), a[i]) - b.begin());
		reverse(a.begin(), a.end());

		long long ans = 0;
		BIT bit(n);
		for (int i = 0; i < n; i++) {
			ans += bit.query(a[i]);
			bit.update(a[i] + 1, 1);
		}
		cout << "Case #" << ++Case << ": " << ans << '\n';
	}
}
