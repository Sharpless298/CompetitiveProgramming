#include <bits/stdc++.h>
using namespace std;

int f(int x, int y) {
	if (x % 3 == 2 && y % 3 == 2)
		return x + y + 2;
	return x + y;
}

struct node {
	int x, y;
	bool operator<(const node &a) const {
		if (f(x, y) != f(a.x, a.y))
			return f(x, y) < f(a.x, a.y);
		if (x != a.x)
			return x < a.x;
		return y < a.y;
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

		set<node> s0, s1;
		for (int i = 0; i < 2 * sqrt(n); i++) {
			for (int j = 0; j < 2 * sqrt(n); j++) {
				s1.insert((node){i * 3 + 1, j * 3 + 1});
				for (int k = 0; k <= 1; k++) {
					for (int l = 0; l <= 1; l++) {
						s0.insert((node){i * 3 + 1 + k, j * 3 + 1 + l});
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;

			if (t == 0) {
				auto k = *s1.begin();
				s0.erase(k);
				s1.erase(k);
				cout << k.x << ' ' << k.y << '\n';
			} else {
				auto k = *s0.begin();
				s0.erase(k);
				s1.erase(k);
				cout << k.x << ' ' << k.y << '\n';
			}
		}
	}
}
