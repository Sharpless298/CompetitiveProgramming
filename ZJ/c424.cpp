#include <iostream>
using namespace std;

const int INF = 2e9;

bool f;
int T, n, ary[5005], ans, mx, mn;

bool check(int i, int j) {
	return abs(ary[i] - ary[j]) == (j - i) && mx < max(ary[i], ary[j]) && mn > min(ary[i], ary[j]);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;

	while (T--) {
		ans = 0;

		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> ary[i];

		for (int i = 0; i < n - 1; i++) {
			mx = -INF, mn = INF;
			for (int j = i + 1; j < n; j++) {
				if (check(i, j))
					ans++;
				mx = max(mx, ary[j]);
				mn = min(mn, ary[j]);
			}
		}

		cout << ans << '\n';
	}
}
