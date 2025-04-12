#include <iostream>
using namespace std;

typedef long long int lli;

const lli INF = 9e18;

int n;
lli ans, t, ary[505][505], pre[505][505];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ans = 0;

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> ary[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			pre[i][j] = pre[i - 1][j] + ary[i][j];

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			t = 0;
			for (int k = 1; k <= n; k++) {
				t = max(t + pre[j][k] - pre[i - 1][k], pre[j][k] - pre[i - 1][k]);
				ans = max(ans, t);
			}
		}
	}

	cout << ans << '\n';
}
