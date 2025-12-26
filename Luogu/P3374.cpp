#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BIT {
	int n;
	vector<T> bit;

	BIT(int _n) : n(_n) {
		bit.assign(n + 1, 0);
	}

	void update(int i, T x) {
		for (; i <= n; i += (i & -i)) {
			bit[i] += x;
		}
	}

	T query(int i) {
		T sum = 0;
		for (; i; i -= (i & -i)) {
			sum += bit[i];
		}
		return sum;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	BIT<long long> bit(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		bit.update(i + 1, x);
	}

	while (m--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, k;
			cin >> x >> k;
			bit.update(x, k);
		} else {
			int x, y;
			cin >> x >> y;
			cout << bit.query(y) - bit.query(x - 1) << '\n';
		}
	}
}
