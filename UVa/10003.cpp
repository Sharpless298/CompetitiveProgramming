#include <cstring>
#include <iostream>
using namespace std;

const int INF = 2e9;

int L, n, a[128], dp[1024][1024];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> L && L) {
		memset(dp, 0, sizeof(dp));

		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		a[n + 1] = L;

		for (int i = 2; i < n + 2; i++) {
			for (int l = 0, r = i; r <= n + 1; l++, r++) {
				dp[a[l]][a[r]] = INF;
				for (int k = l + 1; k < r; k++)
					dp[a[l]][a[r]] = min(dp[a[l]][a[r]], dp[a[l]][a[k]] + dp[a[k]][a[r]] + a[r] - a[l]);
			}
		}

		cout << "The minimum cutting is " << dp[0][L] << ".\n";
	}
}
