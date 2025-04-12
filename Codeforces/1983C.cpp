#include <iostream>
using namespace std;

typedef long long int lli;

int a[3][200005], ans[3][2];

void solve() {
	int n;
	lli tot = 0;

	cin >> n;
	for (int i = 0; i < 3; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	for (int i = 1; i <= n; i++)
		tot += a[0][i];
	tot = (tot + 2) / 3;

	for (int i = 0; i < 3; i++) {
		int l = 1;
		lli sum = 0;

		while (sum < tot)
			sum += a[i][l++];
		ans[i][0] = 1;
		ans[i][1] = l - 1;
		for (int j = 0; j < 3; j++) {
			if (i == j)
				continue;

			int r = l;
			sum = 0;
			while (r <= n && sum < tot)
				sum += a[j][r++];
			if (sum < tot)
				continue;
			ans[j][0] = l;
			ans[j][1] = r - 1;

			int k = 3 - i - j;
			ans[k][0] = r;
			ans[k][1] = n;
			sum = 0;
			while (r <= n)
				sum += a[k][r++];
			if (sum < tot)
				continue;
			for (int i = 0; i < 3; i++)
				cout << ans[i][0] << ' ' << ans[i][1] << ' ';
			cout << '\n';
			return;
		}
	}

	cout << "-1\n";
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--)
		solve();
}
