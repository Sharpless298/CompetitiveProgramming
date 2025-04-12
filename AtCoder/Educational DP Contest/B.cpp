#include <cstring>
#include <iostream>
using namespace std;

int n, k;
int ary[100005], dp[100005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> ary[i];

	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		dp[i] = 0x3f3f3f3f;

		for (int j = 1; i - j >= 0 && j <= k; j++)
			dp[i] = min(dp[i], dp[i - j] + abs(ary[i] - ary[i - j]));
	}

	cout << dp[n - 1] << '\n';
}
