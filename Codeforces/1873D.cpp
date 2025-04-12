#include <iostream>
using namespace std;

const int MAXN = 2e5 + 5;

char ary[MAXN];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t, n, k, ans;

	cin >> t;

	while (t--) {
		ans = 0;

		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> ary[i];

		for (int i = 0; i < n; i++) {
			if (ary[i] == 'B') {
				ans++;
				i += (k - 1);
			}
		}

		cout << ans << '\n';
	}
}
