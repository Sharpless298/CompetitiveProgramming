#include <bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & -x)

template <typename T>
struct BIT {
	int n, m;
	vector<vector<T>> bit;
	
	BIT(int _n, int _m) {
		n = _n;
		m = _m;
		bit.assign(n + 1, vector<T>(m + 1));
	}
	
	void update(int r, int c, T x) {
		r++, c++;
		for (; r <= n; r += lowbit(r)) {
			for (int i = c; i <= m; i += lowbit(i)) {
				bit[r][i] += x;
			}
		}
	}
	
	T query(int r, int c) {
		T sum = 0;
		for (; r > 0; r -= lowbit(r)) {
			for (int i = c; i > 0; i -= lowbit(i)) {
				sum += bit[r][i];
			}
		}
		return sum;
	}

	T query(int r1, int c1, int r2, int c2) {
		return query(r2, c2) - query(r2, c1) - query(r1, c2) + query(r1, c1);
	}
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, q;
	cin >> n >> q;
	vector<string> G(n);
	BIT<int> bit(n, n);
	for (int i = 0; i < n; i++) {
		cin >> G[i];
		for (int j = 0; j < n; j++) {
			if (G[i][j] == '*') {
				bit.update(i, j, 1);
			}
		}
	}

	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int y, x;
			cin >> y >> x;
			y--, x--;
			G[y][x] ^= '.' ^ '*';
			bit.update(y, x, G[y][x] == '.' ? -1 : 1);
		} else {
			int y1, x1, y2, x2;
			cin >> y1 >> x1 >> y2 >> x2;
			y1--, x1--;
			cout << bit.query(y1, x1, y2, x2) << '\n';
		}
	}
}
