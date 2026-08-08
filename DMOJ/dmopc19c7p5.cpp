\\ TLE

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("avx2")

struct BIT {
	int n;
	vector<vector<int>> bit;
	vector<vector<int>> vals;

	BIT(int _n, vector<array<int, 2>> &v) {
		n = _n;
		sort(v.begin(), v.end(), [](const auto &x, const auto &y) {
			return x[1] < y[1];
		});
		vals.resize(n + 1);
		bit.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			vals[i].push_back(0);
		}
		for (auto [r, c] : v) {
			r++, c++;
			for (; r <= n; r += r & -r) {
				if (vals[r].back() != c) {
					vals[r].push_back(c);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			bit[i].resize(vals[i].size());
		}
	}

	int idx(vector<int> &v, int x) {
		return (int)(upper_bound(v.begin(), v.end(), x) - v.begin() - 1);
	}

	void update(int r, int c, int val) {
		r++, c++;
		for (; r <= n; r += r & -r) {
			for (int i = idx(vals[r], c); i < (int)bit[r].size(); i += i & -i) {
				bit[r][i] += val;
			}
		}
	}

	int64_t query(int r, int c) {
		int64_t sum = 0;
		for (; r > 0; r -= r & -r) {
			for (int i = idx(vals[r], c); i > 0; i -= i & -i) {
				assert(i != 0);
				sum += bit[r][i];
			}
		}
		return sum;
	}

	int64_t query(int r1, int c1, int r2, int c2) {
		return query(r2, c2) - query(r2, c1) - query(r1, c2) + query(r1, c1);
	}
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}
	vector<array<int, 2>> events(n);
	for (int i = 0; i < n; i++) {
		events[i] = {p[i], a[p[i]]};
	}
	BIT bit(n, events);
	int64_t ans = 0;
	for (int i = 0; i < n; i++) {
		ans += bit.query(0, a[p[i]] + 1, p[i], n);
		ans += bit.query(p[i] + 1, 0, n, a[p[i]]);
		cout << ans << '\n';
		bit.update(p[i], a[p[i]], 1);
	}
}
