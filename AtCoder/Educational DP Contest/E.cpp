#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, W, V = 0;

	cin >> n >> W;
	vector<int> w(n), v(n);
	for (int i = 0; i < n; i++)
		cin >> w[i] >> v[i], V += v[i];

	vector<int> dp(V + 1, INF);
	dp[0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = V; j >= v[i]; j--)
			dp[j] = min(dp[j], dp[j - v[i]] + w[i]);

	int ans = 0;
	for (int i = 0; i <= V; i++)
		if (dp[i] <= W)
			ans = max(ans, i);

	cout << ans << '\n';
}
