#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BIT {
	int n;
	vector<T> bit;

	BIT(int _n) {
		n = _n;
		bit.assign(n + 1, 0);
	}

	void update(int i, T x) {
		i++;
		for (; i <= n; i += (i & -i)) {
			bit[i] += x;
		}
	}

	// query[0, i)
	T query(int i) {
		T sum = 0;
		for (; i; i -= (i & -i)) {
			sum += bit[i];
		}
		return sum;
	}
};

const int shift = 1e6;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<array<int, 4>> a;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (y1 == y2) {
			a.push_back({y1, 2, x1, x2});
		} else {
			a.push_back({y1, 1, x1, x2});
			a.push_back({y2, 3, x1, x2});
		}
	}
	sort(a.begin(), a.end());
	BIT<int64_t> bit(2 * shift + 1);
	int64_t ans = 0;
	for (auto [y, type, x1, x2] : a) {
		x1 += shift;
		x2 += shift;
		if (type == 1) {
			bit.update(x1, 1);
		} else if (type == 2) {
			ans += bit.query(x2 + 1) - bit.query(x1);
		} else {
			bit.update(x1, -1);
		}
	}
	cout << ans << '\n';
}
