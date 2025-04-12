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

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (int &i : a)
			cin >> i;
		for (int &i : b)
			cin >> i;

		vector<int> c = a, d = b;
		sort(c.begin(), c.end());
		sort(d.begin(), d.end());
		if (c != d) {
			cout << "NO\n";
			continue;
		}

		c.resize(unique(c.begin(), c.end()) - c.begin());
		for (int i = 0; i < n; i++) {
			a[i] = (int)(lower_bound(c.begin(), c.end(), a[i]) - c.begin());
			b[i] = (int)(lower_bound(c.begin(), c.end(), b[i]) - c.begin());
		}

		long long cnt1 = 0, cnt2 = 0;
		BIT bit1(n), bit2(n);
		for (int i = 0; i < n; i++) {
			cnt1 += bit1.query(a[i]);
			bit1.update(a[i] + 1, 1);
			cnt2 += bit2.query(b[i]);
			bit2.update(b[i] + 1, 1);
		}

		cout << (cnt1 % 2 == cnt2 % 2 ? "YES\n" : "NO\n");
	}
}
