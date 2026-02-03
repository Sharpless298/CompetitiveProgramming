#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> parent, sz;

	DSU(int _n) {
		parent.resize(_n);
		iota(parent.begin(), parent.end(), 0);
		sz.assign(_n, 1);
	}

	int find(int x) {
		return parent[x] == x ? x : parent[x] = find(parent[x]);
	}

	bool unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) {
			return false;
		}
		if (sz[x] > sz[y]) {
			swap(x, y);
		}
		parent[x] = y;
		sz[y] += sz[x];
		return true;
	}
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		vector<int> cnt(3 * n);
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				cnt[3 * i] = i;
				cnt[3 * i + 2] = n - i - 1;
			} else {
				cnt[3 * i + 1] = 1;
			}
		}

		DSU dsu(3 * n);
		auto merge = [&](int x, int y) {
			if (cnt[x] > 0 && cnt[y] > 0) {
				dsu.unite(x, y);
			}
		};
		for (int i = 0; i < n - 1; i++) {
			merge(3 * i, 3 * i + 3);
			merge(3 * i + 1, 3 * i + 3);
			merge(3 * i + 2, 3 * i + 4);
			merge(3 * i + 2, 3 * i + 5);
		}

		vector<long long> sum(3 * n);
		for (int i = 0; i < 3 * n; i++) {
			sum[dsu.find(i)] += cnt[i];
		}
		cout << *max_element(sum.begin(), sum.end()) << '\n';
	}
}
